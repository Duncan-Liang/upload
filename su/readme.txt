[Description]
user�汾��ô��rootȨ��
 
[Keyword]
user root adb superuser �û��汾 rootȨ�� security
 
[Serious Declaration]
��������: �κ�������user�汾�ϴ�rootȨ�޵��ַ�������û�������ȫ����, ����ϸ�������������Ƿ���ʵ��Ҫ. MTK ǿ�ҷ��Դ�������, �ɴ˴����İ�ȫ���գ��Լ���ɵ���ʧ, MTK ���е��κε����Ρ�
 
[Solution]
������Ҫȷ�������뿪��adbd ��root Ȩ�ޣ�������app Ҳ�����õ�root Ȩ�ޡ�����֮��Ĳ�𣬿��Բο�FAQ
FAQ08317:android apk ��root Ȩ�޺�USB adb Ȩ�޵�����  https://online.mediatek.com/Pages/FAQ.aspx?List=SW&FAQID=FAQ08317
 
(1). adbd ��root Ȩ��
����ͨ����debug user �汾����ʱ, ���߽���user �汾��monkey test ʱ��������������Ա�debug. ���Բο�FAQ.
FAQ06317 ��������Կ���adb ��rootȨ�� https://online.mediatek.com/Pages/FAQ.aspx?List=SW&FAQID=FAQ06317
 
�������user �汾adb root Ȩ��Ĭ�Ϲر�, �����뿪��ʱ, ����ͨ������ģʽ�е��������, ��ô��USER2ROOT ���� (L �汾����֧�ִ˹���)��
�˹���Ĭ�Ϲر�, �������, ��Ҫ��ProjectConfig.mk ������: MTK_USER_ROOT_SWITCH = yes
ͬ��ע������ͨ��ֻ����debug ���� cmcc �Ͳ�, ����ʽ�����汾, ǿ��Ҫ��ر�, �����а�ȫ����.
 
(2). app ��root Ȩ��
app ��root Ȩ��ͨ����ͨ��ִ��su ��������ȡ��ע�����KK ��, ��Ϊ��������, ��ͨ��su ����ֱ���õ�root Ȩ��, ��Ҫ������ԵĸĶ�.
ͨ�����ǻ����þ��п��ƶ˵ĵ�����su, ����������SuperSU, �Լ�ʹ��Google default su Ϊ������˵����
 
(3). ������õ�����SuperSU
�÷�ʽ�����ƹ�zygote �� adbd ��Root Capabilities BoundSet ������. MTK Ŀǰ������KK �Լ���ǰ�İ汾, L �汾����ΪSuperSU ���ڳ���������, ��ͻ��鿴��������˵��.
3.1. ����SuperSU
 SuperSU: http://forum.xda-developers.com/showthread.php?t=1538053
 
3.2. ����Superuser.apk �� system/app
   ��su ���Ʋ�������: daemonsu
   ����su �� system/xbin
   ����daemonsu �� system/xbin
   ����chattr �� system/xbin
   ����chattr.pie �� /system/xbin
 
3.3. ����install-recovery.sh ��system/etc
���Ұ���FAQ:  FAQ09021 ����޸�ϵͳ�����ļ���Ȩ��, �û������� https://online.mediatek.com/Pages/FAQ.aspx?List=SW&FAQID=FAQ09021
����alps/system/core/inlcude/private/android_filesystem_config.h
��android_files ������ʼ����.
{ 00755, AID_ROOT,      AID_ROOT,      0, "system/etc/install-recovery.sh" },
 
(4). �������Google default su
4.1 �ſ�Google default su ֻ׼shell/root �û�ʹ�õ�����.
    system/extras/su/su.c ��ɾ������3�д���
    if (myuid != AID_ROOT && myuid != AID_SHELL) {
        fprintf(stderr,"su: uid %d not allowed to su\n", myuid);
        return 1;
    }
 
4.2 ���Ƚ��˱������su ���õ�system/bin, Ȼ���޸�su ������Ȩ��,����sbit λ.
����FAQ:  FAQ09021 ����޸�ϵͳ�����ļ���Ȩ��, �û������� https://online.mediatek.com/Pages/FAQ.aspx?List=SW&FAQID=FAQ09021
����alps/system/core/inlcude/private/android_filesystem_config.h
��android_files ������
����
{ 06755, AID_ROOT,      AID_ROOT,      0, "system/bin/su" },
ע������Ҫ����
{ 00755, AID_ROOT,      AID_SHELL,     0, "system/bin/*" },
֮ǰ
 
4.3 �����KK �汾(��KK2 MT6752/MT6732), ��Ҫǿ�н��zygote �� adbd ��Root Capabilities BoundSet ������
����kernel/security/commoncap.c �� cap_prctl_drop ����Ϊ:
static long cap_prctl_drop(struct cred *new, unsigned long cap)
{
  //mtk71029 add begin: Let 'zygote' and 'adbd' drop Root Capabilities BoundSet ineffectively
        if (!strncmp(current->comm, "zygote", 16)) {
                return -EINVAL;
        }
        if (!strncmp(current->comm, "adbd", 16)) {
                return -EINVAL;
        }
        // add end
        if (!capable(CAP_SETPCAP))
                return -EPERM;
        if (!cap_valid(cap))
                return -EINVAL;
        cap_lower(new->cap_bset, cap);
        return 0;
}
 
4.4 �����˾һ��Ҫ��K2(MT6752/MT6732) �Ͽ���, ���ύeService, ���붨�Ƶ�DVM, �ſ���ص�Ȩ������.
 
 
4.5 �����˾��L �汾����, �밴���������:
 4.5.1 ����alps/frameworks/base/core/jni/com_android_internal_os_Zygote.cpp  
  �� DropCapabilitiesBoundingSet(JNIEnv* env) ��������ÿ�.

 4.5.2 ����alps/frameworks/base/cmds/app_process/app_main.cpp ��main ����, ע�͵�main������ʼ��������δ���
  if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0) < 0) {
   // Older kernels don't understand PR_SET_NO_NEW_PRIVS and return
   // EINVAL. Don't die on such kernels.
   if (errno != EINVAL) {
    LOG_ALWAYS_FATAL("PR_SET_NO_NEW_PRIVS failed: %s", strerror(errno));
    return 12;
   }
  }

 4.5.3 ����alps/system/core/adb/adb.c ��should_drop_privileges() ����, ������������ֱ�ӷ��� 0 ����.

 4.5.4 ��SELinux ������permissve mode, �ο�FAQ11484: http://online.mediatek.inc/Pages/FAQ.aspx?List=SW&FAQID=FAQ11484
  
 
���±���ϵͳ, ����download ��, adb shell �����������su �����Ƿ���������$�л���#, ����л����ɹ���
 
(5). ��KK �汾��app ʹ��root Ȩ���ܵ������ϸ������, ���Բο�FAQ
[FAQ11414] android KK 4.4 �汾��user �汾su Ȩ�����ر���������˵��
http://online.mediatek.inc/Pages/FAQ.aspx?List=SW&FAQID=FAQ11414
FAQ11538��android KK 4.4 �汾��app ʹ��root(su) Ȩ���ܵ��ϸ�����˵��
https://online.mediatek.com/Pages/FAQ.aspx?List=SW&FAQID=FAQ11538