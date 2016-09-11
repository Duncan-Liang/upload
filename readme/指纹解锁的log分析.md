###  指纹解锁成功的log
2016/09.11

用指纹进行，截取部分的main_log,这里的sys_log看不出有用的信息
```
01-02 23:03:21.052053: D/KeyguardUpdateMonitor(1080): handleKeyguardReset
01-02 23:03:21.052191: D/KeyguardUpdateMonitor(1080): handleKeyguardVisibilityChanged(1)
开始指纹的监听
01-02 23:03:21.069808: V/KeyguardUpdateMonitor(1080): startListeningForFingerprint()
01-02 23:03:21.071816: V/fingerprintd(372): authenticate(sid=0, gid=0)
01-02 23:03:21.207644: D/KeyguardUpdateMonitor(1080): onAuthenticationError errId:5
01-02 23:03:21.780398: D/fingerprintd(372): onAcquired(0)
01-02 23:03:21.780526: D/fingerprintd(372): onAuthenticated(fid=0, gid=0)
01-02 23:03:21.781016: D/KeyguardUpdateMonitor(1080): onAuthenticationAcquired info:0
01-02 23:03:21.781442: D/KeyguardUpdateMonitor(1080): onAuthenticationFailed
01-02 23:03:22.221866: D/fingerprintd(372): onAcquired(0)
01-02 23:03:22.223898: D/KeyguardUpdateMonitor(1080): onAuthenticationAcquired info:0
01-02 23:03:22.225030: D/fingerprintd(372): onAuthenticated(fid=1, gid=0)
这里进入到守护进程中去进行指纹认证，通过进行多指测试，可以知道这里的fid=1表示的是指纹的编号
01-02 23:03:22.229191: D/KeyguardUpdateMonitor(1080): onAuthenticationSucceeded
出现onAuthenticationSucceeded则表示用指纹解锁认证成功
01-02 23:03:22.230082: V/fingerprintd(372): stopAuthentication()
01-02 23:03:22.263363: D/KeyguardUpdateMonitor(1080): setFingerprintRunningDetectionRunning:false
01-02 23:03:22.308365: D/KeyguardUpdateMonitor(1080): onAuthenticationError errId:5
01-02 23:03:22.335467: V/KeyguardUpdateMonitor(1080): *** unregister callback for com.android.keyguard.KeyguardPatternView$2@8846931
01-02 23:03:22.335979: V/KeyguardUpdateMonitor(1080): *** unregister callback for com.android.keyguard.CarrierText$1@553e816
解除一些callback的操作
。。。。。。。
。。。。。。。
01-02 23:03:22.338023: D/KeyguardUpdateMonitor(1080): sendKeyguardVisibilityChanged(false)
01-02 23:03:22.398459: D/KeyguardUpdateMonitor(1080): handleKeyguardVisibilityChanged(0)
```
###  指纹解锁失败的log

```
01-01 13:19:37.102267: D/KeyguardUpdateMonitor(1849): handleKeyguardReset
01-01 13:19:37.102393: D/KeyguardUpdateMonitor(1849): handleKeyguardVisibilityChanged(1)
开始指纹的监听
01-01 13:19:37.117305: V/KeyguardUpdateMonitor(1849): startListeningForFingerprint()
01-01 13:19:37.119862: V/fingerprintd(959): authenticate(sid=0, gid=0)
01-01 13:19:37.119918: D/KeyguardUpdateMonitor(1849): setFingerprintRunningDetectionRunning:true
01-01 13:19:37.145965: D/KeyguardUpdateMonitor(1849): handleStartedWakingUp
01-01 13:19:37.156598: D/KeyguardUpdateMonitor(1849): onAuthenticationError errId:5
注意，下面这段是多次使用不匹配的指纹进行解锁的log
多次出现onAuthenticationFailed，表示指纹认证失败
并且没有出现onAuthenticationSucceeded，说明只有出现onAuthenticationSucceeded才表示用指纹解锁成功
01-01 13:19:39.373656: D/fingerprintd(959): onAcquired(0)
01-01 13:19:39.373855: D/fingerprintd(959): onAuthenticated(fid=0, gid=0)
01-01 13:19:39.375133: D/KeyguardUpdateMonitor(1849): onAuthenticationAcquired info:0
01-01 13:19:39.375734: D/KeyguardUpdateMonitor(1849): onAuthenticationFailed
01-01 13:19:41.699205: D/fingerprintd(959): onAcquired(0)
01-01 13:19:41.699449: D/fingerprintd(959): onAuthenticated(fid=0, gid=0)
01-01 13:19:41.703535: D/KeyguardUpdateMonitor(1849): onAuthenticationAcquired info:0
01-01 13:19:41.703623: D/KeyguardUpdateMonitor(1849): onAuthenticationFailed
01-01 13:19:43.012061: D/fingerprintd(959): onAcquired(0)
01-01 13:19:43.012284: D/fingerprintd(959): onAuthenticated(fid=0, gid=0)
01-01 13:19:43.015830: D/KeyguardUpdateMonitor(1849): onAuthenticationAcquired info:0
01-01 13:19:43.015900: D/KeyguardUpdateMonitor(1849): onAuthenticationFailed
01-01 13:19:45.183196: D/fingerprintd(959): onAcquired(0)
01-01 13:19:45.183371: D/fingerprintd(959): onAuthenticated(fid=0, gid=0)
01-01 13:19:45.186428: D/KeyguardUpdateMonitor(1849): onAuthenticationAcquired info:0
01-01 13:19:45.186508: D/KeyguardUpdateMonitor(1849): onAuthenticationFailed
01-01 13:19:47.165273: D/KeyguardUpdateMonitor(1849): sendKeyguardBouncerChanged(true)
01-01 13:19:47.195474: D/KeyguardUpdateMonitor(1849): handleKeyguardBouncerChanged(1)
01-01 13:19:47.578324: V/KeyguardUpdateMonitor(1849): *** unregister callback for com.android.systemui.statusbar.policy.KeyguardMonitor@d7228a6
01-01 13:19:49.061255: V/KeyguardUpdateMonitor(1849): *** unregister callback for com.android.keyguard.KeyguardPatternView$2@c906d96
01-01 13:19:49.062693: V/KeyguardUpdateMonitor(1849): *** unregister callback for com.android.keyguard.CarrierText$1@2e68d17
。。。。。。
。。。。。。
解锁不匹配后使用图案解锁
01-01 13:19:49.067912: D/KeyguardUpdateMonitor(1849): sendKeyguardVisibilityChanged(false)
01-01 13:19:49.067994: D/KeyguardUpdateMonitor(1849): sendKeyguardBouncerChanged(false)
01-01 13:19:49.131862: D/KeyguardUpdateMonitor(1849): handleKeyguardVisibilityChanged(0)
01-01 13:19:49.134288: D/KeyguardUpdateMonitor(1849): handleKeyguardBouncerChanged(0)
01-01 13:19:49.134911: V/KeyguardUpdateMonitor(1849): stopListeningForFingerprint()
01-01 13:19:49.135975: D/KeyguardUpdateMonitor(1849): setFingerprintRunningDetectionRunning:false
01-01 13:19:49.136014: V/fingerprintd(959): stopAuthentication()
01-01 13:19:49.176860: D/KeyguardUpdateMonitor(1849): onAuthenticationError errId:5
```

### 测试提供的指纹解锁无响应的log
```
08-04 13:56:11.499233: V/KeyguardUpdateMonitor(2463): startListeningForFingerprint()
08-04 13:56:11.526023: V/fingerprintd(1553): stopAuthentication()
。。。。
08-04 13:56:11.758835: D/KeyguardUpdateMonitor(2463): sendKeyguardVisibilityChanged(true)
08-04 13:56:12.065461: V/fingerprintd(1553): stopAuthentication()
08-04 13:56:12.259941: D/KeyguardUpdateMonitor(2463): onAuthenticationError errId:5
08-04 13:56:12.260588: D/KeyguardUpdateMonitor(2463): handleKeyguardReset
08-04 13:56:12.260693: D/KeyguardUpdateMonitor(2463): handleKeyguardVisibilityChanged(1)
08-04 13:56:12.280662: D/KeyguardUpdateMonitor(2463): handleStartedWakingUp
注意到这里的log，这个时候从log来看就是所说没有响应，而且一直没有出现onAuthenticationSucceeded和onAuthenticationFailed
表面这里是既没匹配成功，又没出现认证失败的提示信息
从KeyguardUpdateMonitor调到fingerprintd，却一直卡在onAcquired和onAuthenticated这两个方法这里
另外，由这个时间点去sys_log中找信息，却在对应的时间段内sys_log一条记录都没有
仅仅从这些信息是找不到问题的原因的
08-04 13:56:12.849213: D/fingerprintd(1553): onAcquired(0)
08-04 13:56:12.849315: D/fingerprintd(1553): onAuthenticated(fid=0, gid=0)
08-04 13:56:13.377919: D/fingerprintd(1553): onAcquired(0)
08-04 13:56:13.378022: D/fingerprintd(1553): onAuthenticated(fid=4, gid=0)
08-04 13:56:14.070258: D/fingerprintd(1553): onAcquired(0)
08-04 13:56:14.070364: D/fingerprintd(1553): onAuthenticated(fid=4, gid=0)
08-04 13:56:14.545329: D/fingerprintd(1553): onAcquired(0)
08-04 13:56:14.545435: D/fingerprintd(1553): onAuthenticated(fid=4, gid=0)
08-04 13:56:14.960202: D/fingerprintd(1553): onAcquired(0)
08-04 13:56:14.960314: D/fingerprintd(1553): onAuthenticated(fid=4, gid=0)
08-04 13:56:15.424211: D/fingerprintd(1553): onAcquired(0)
08-04 13:56:15.424325: D/fingerprintd(1553): onAuthenticated(fid=4, gid=0)
08-04 13:56:15.941730: D/fingerprintd(1553): onAcquired(0)
08-04 13:56:15.941841: D/fingerprintd(1553): onAuthenticated(fid=4, gid=0)
08-04 13:56:16.522564: D/fingerprintd(1553): onAcquired(0)
08-04 13:56:16.522708: D/fingerprintd(1553): onAuthenticated(fid=4, gid=0)
08-04 13:56:17.167257: D/fingerprintd(1553): onAcquired(0)
08-04 13:56:17.167369: D/fingerprintd(1553): onAuthenticated(fid=4, gid=0)
08-04 13:56:17.776727: D/fingerprintd(1553): onAcquired(0)
08-04 13:56:17.776860: D/fingerprintd(1553): onAuthenticated(fid=4, gid=0)
08-04 13:56:18.282351: D/fingerprintd(1553): onAcquired(0)
08-04 13:56:18.282459: D/fingerprintd(1553): onAuthenticated(fid=0, gid=0)
08-04 13:56:18.795893: D/fingerprintd(1553): onAcquired(0)
08-04 13:56:18.796647: D/fingerprintd(1553): onAuthenticated(fid=0, gid=0)
08-04 13:56:23.024505: D/KeyguardUpdateMonitor(2463): handleKeyguardReset
08-04 13:56:24.003017: D/KeyguardUpdateMonitor(2463): handleStartedWakingUp
08-04 13:56:25.849758: D/fingerprintd(1553): onAcquired(0)
08-04 13:56:25.849871: D/fingerprintd(1553): onAuthenticated(fid=4, gid=0)
08-04 13:56:27.727598: D/KeyguardUpdateMonitor(2463): sendKeyguardBouncerChanged(true)
08-04 13:56:27.739953: D/KeyguardUpdateMonitor(2463): handleKeyguardBouncerChanged(1)
08-04 13:56:27.743924: V/KeyguardUpdateMonitor(2463): *** unregister callback for 
08-04 13:56:29.376645: V/fingerprintd(1553): authenticate(sid=0, gid=0)
08-04 13:56:29.412960: V/KeyguardUpdateMonitor(2463): *** unregister callback for com.android.keyguard.KeyguardPatternView$2@a1cb8cc
。。。。。
08-04 13:56:29.420984: D/KeyguardUpdateMonitor(2463): sendKeyguardVisibilityChanged(false)
08-04 13:56:29.421034: D/KeyguardUpdateMonitor(2463): sendKeyguardBouncerChanged(false)
08-04 13:56:29.446461: D/KeyguardUpdateMonitor(2463): handleKeyguardVisibilityChanged(0)
08-04 13:56:29.448158: D/KeyguardUpdateMonitor(2463): handleKeyguardBouncerChanged(0)
停止指纹的监听
08-04 13:56:29.448423: V/KeyguardUpdateMonitor(2463): stopListeningForFingerprint()
08-04 13:56:29.448853: D/KeyguardUpdateMonitor(2463): setFingerprintRunningDetectionRunning:false
08-04 13:56:30.854097: V/KeyguardUpdateMonitor(2463): *** register callback for com.android.systemui.statusbar.policy.KeyguardMonitor@94d3281
08-04 13:56:30.854193: V/KeyguardUpdateMonitor(2463): *** unregister callback for null
08-04 13:56:31.517947: V/fingerprintd(1553): stopAuthentication()
08-04 13:56:31.914918: V/KeyguardUpdateMonitor(2463): *** unregister callback for com.android.systemui.statusbar.policy.KeyguardMonitor@94d3281

```
### 指纹录入无响应的log

```
08-04 15:50:34.857477: D/FingerprintHal(1594): bio_pre_enroll
08-04 15:50:34.860010: E/FingerprintHal(1594): trustkernel_tac_pre_enroll challenge: 0xd5234c306edc1dd6
开始指纹的录入
08-04 15:50:37.359290: V/fingerprintd(1594): enroll(gid=0, timeout=60)
08-04 15:50:37.359325: E/FingerprintHal(1594): fingerprint_enroll
08-04 15:50:37.359351: D/FingerprintHal(1594): bio_enroll operation_id gid 0x0 timeout_sec 60 challenge: 0xd5234c306edc1dd6
08-04 15:50:37.359370: D/FingerprintHal(1594): cmdqueue: 
08-04 15:50:37.359413: D/FingerprintHal(1594): cmdqueue: <100> 
08-04 15:50:37.359435: D/FingerprintHal(1594): thread_run command type 64 start
08-04 15:50:37.359454: E/FingerprintHal(1594): bio_enroll_work gid 0 timeout 60 s
08-04 15:50:37.359473: E/FingerprintHal(1594): enroll 0xd5234c306edc1dd6
这里终止了指纹的录入操作
08-04 15:51:00.383101: V/fingerprintd(1594): stopEnrollment()
08-04 15:51:00.383148: E/FingerprintHal(1594): fingerprint_cancel
08-04 15:51:00.423404: D/FingerprintHal(1594): command cancelled
08-04 15:51:00.423424: D/FingerprintHal(1594): thread_run command type 64 return 0
08-04 15:51:00.423440: D/FingerprintHal(1594): complete_cmd
08-04 15:51:00.423460: D/FingerprintHal(1594): fetch_cmd

```
