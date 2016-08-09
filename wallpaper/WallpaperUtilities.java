//add by youxiaoyan for SystemUI 20160309 -s

package android.app;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Method;
import java.util.ArrayList;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;

import android.content.Context;
import android.content.res.Configuration;
import android.content.res.Resources;
import android.os.SystemProperties;
import android.text.TextUtils;
import android.util.Log;
import android.util.Xml;

/**
 *
 * This is for AsusWallpaper supporting idCode
 * @hide
 */
public class WallpaperUtilities {
    // ------------------------------------------------------------------------
    // TYPES
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    // STATIC FIELDS
    // ------------------------------------------------------------------------
    private static final String TAG = "WallpaperUtilities";
    private static final boolean DEBUG = false;

    public static final int INVALID_RESOURCE_ID = 0;
    private static final String PROP_IDCODE = "ro.config.idcode";
    protected static final String CUSTOMIZE_RES_PACKAGE_NAME = "com.asus.LauncherRes";
    private static final String RES_CUSTOMIZE_ROOT_PATH = "/system/vendor/etc";
    private static final String RES_VERSA_DEFAULT_FOLDER_NAME = "Generic";
    private static final String WALLPAPER_PATH = "/Launcher/wallpapers";
    private static final String RES_CUSTOMIZE_ETC_ROOT_PATH = "/system/etc/LauncherRes";
    private static final String WALLPAPER_LIST_FILENAME = "wallpaper_list.xml";

    // ------------------------------------------------------------------------
    // STATIC INITIALIZERS
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // STATIC METHODS
    // ------------------------------------------------------------------------
    private static String getColorIdCode() {
        // perfect match
        String idCode = SystemProperties.get(PROP_IDCODE, "").toLowerCase();
        Log.v(TAG, "getColorIdCode: " + idCode);
        // default load 1a if idcode not defined
        if (TextUtils.isEmpty(idCode) || idCode.equals("unknown")) {
            idCode = "1a";
        }

        return idCode;
    }

    private static String getPartialMatchedColorIdCode(String idCode) {
        // partial match last char, load 1x for 6x, 7x, 8x , and etc.
        if (idCode.length() > 1) {
            idCode = 1 + idCode.substring(idCode.length() - 1);
            Log.v(TAG, "get partial matched idcode: " + idCode);
        }
        return idCode;
    }

    private static String mappingColorIdCodeForZf2(String idCode) {
        // for zenfone2 wallpaper style 20141225
        // mapping all to 1x
        // and mapping 1b to 1a
        String mappingIdCode = idCode;
        if (isZf2List()) {
            if (idCode.length() > 1) {
                mappingIdCode = idCode.substring(idCode.length() - 1);
                if ("b".equals(mappingIdCode)) {
                    mappingIdCode = "a";
                }
                mappingIdCode = 1 + mappingIdCode;
                Log.v(TAG, "mappingIdCode from " + idCode + " to " + mappingIdCode);
            }
        }
        return mappingIdCode;
    }

    private static ArrayList<String> getMappingListForColorId() {
        final ArrayList<String> mappingList = new ArrayList<String>();
        // 1.Perfect mapping for the idcode
        final String idCode = getColorIdCode();
        mappingList.add(idCode);
        // 2.Partial matching
        final String partialIdCode = getPartialMatchedColorIdCode(idCode);
        if (!idCode.equals(partialIdCode)) {
            mappingList.add(partialIdCode);
        }
        // 3.Special mappings
        final String spIdCode = mappingColorIdCodeForZf2(partialIdCode);
        if (!partialIdCode.equals(spIdCode)) {
            mappingList.add(spIdCode);
        }
        return mappingList;
    }

    protected static Resources getLauncherResources(Resources res) {
        final String res_apk_path = "/system/app/AsusLauncherRes.apk";
        final String packageName_assetManager = "android.content.res.AssetManager";
        final String method_addAssetPath="addAssetPath";

        Class<?> asm_cls = null;
        Object asm_obj = null;
        Method addAssetPath = null;
        try {
            asm_cls = Class.forName(packageName_assetManager);
            asm_obj = asm_cls.getDeclaredConstructor((Class[]) null)
                    .newInstance((Object[]) null);
            addAssetPath = asm_obj.getClass().getDeclaredMethod(
                    method_addAssetPath, new Class[] { String.class });
            addAssetPath.invoke(asm_obj, new Object[] { res_apk_path });
            res = Resources.class.getDeclaredConstructor(
                    new Class[] { asm_obj.getClass(),
                            res.getDisplayMetrics().getClass(),
                            res.getConfiguration().getClass() }).newInstance(
                    new Object[] { asm_obj, res.getDisplayMetrics(),
                            res.getConfiguration() });
            return res;
        } catch (Resources.NotFoundException e) {
        } catch (Exception e2) {
        }
        return null;
    }

    protected static int getDefaultWallpaperResId(Resources res, String defPackage) {
        if (defPackage == null) {
            defPackage = "android";
        }
        for (String idCode : getMappingListForColorId()){
            int resId = res.getIdentifier("default_wallpaper_" + idCode, "drawable", defPackage);
            if (resId != INVALID_RESOURCE_ID) {
                return resId;
            }
        }
        return INVALID_RESOURCE_ID;
    }

    protected static String getADFDefaultWallpaperFilePath(Context context) {
        String[] cusWallpaperList = getWallpaperListInOrder(context,
                WALLPAPER_LIST_FILENAME, getWallpaperFolderPath());
        String rtn = null;
        if (cusWallpaperList != null) {
            if (cusWallpaperList.length > 0) {
                rtn = getWallpaperFilePathFromADF(cusWallpaperList[0]);//use ADF
                if (DEBUG) Log.v(TAG, "getADFDefaultWallpaperFilePath: "+rtn);
            }
        }
        return rtn;
    }

    protected static String getEtcResDefaultWallpaperFilePath(Context context) {
        for (String idCode : getMappingListForColorId()){
            String wallpaperName = (isSupportDds() && isDdsPad(context)) ?
                    "pad_default_wallpaper_" + idCode :
                    "default_wallpaper_" + idCode;
            File[] fileList = getFileStartsWith(getLauncherResFolderPath(), wallpaperName, true);
            if (fileList != null) {
                if (fileList.length > 0) {
                    if (fileList.length > 1) {
                        Log.d(TAG, "EtcDefaultWallpaperFilePath may NOT UNIQUE in folder");
                    }
                    Log.d(TAG, "EtcDefaultWallpaperFilePath: " + fileList[0].toString());
                    return fileList[0].toString();
                }
            }
        }

        return null;
    }

    protected static String getEtcResDefaultWallpaperFilePathForLockscreen(Context context) {
        // perfect match idcode
        final String idCode = "1a";
        String wallpaperName = (isSupportDds() && isDdsPad(context)) ?
                "pad_default_wallpaper_" + idCode :
                "default_wallpaper_" + idCode;
        File[] fileList = getFileStartsWith(getLauncherResFolderPath(), wallpaperName, true);
        if (fileList != null) {
            if (fileList.length > 0) {
                if (DEBUG) {
                    if (fileList.length > 1) {
                        Log.v(TAG, "EtcDefaultWallpaperFilePath may NOT UNIQUE in folder");
                    }
                    Log.v(TAG, "EtcDefaultWallpaperFilePath: " + fileList[0].toString());
                }
                return fileList[0].toString();
            }
        }

        // partial match last char, load 1x for 6x, 7x, 8x , and etc.
        /*final String partialIdCode = getPartialMatchedColorIdCode(idCode);
        wallpaperName = (isSupportDds() && isDdsPad(context)) ?
                "pad_default_wallpaper_" + partialIdCode :
                "default_wallpaper_" + partialIdCode;
        fileList = getFileStartsWith(getLauncherResFolderPath(), wallpaperName, true);
        if (fileList != null) {
            if (fileList.length > 0) {
                if (DEBUG) {
                    if (fileList.length > 1) {
                        Log.v(TAG, "EtcDefaultWallpaperFilePath may NOT UNIQUE in folder");
                    }
                    Log.v(TAG, "EtcDefaultWallpaperFilePath: " + fileList[0].toString());
                }
                return fileList[0].toString();
            }
        }*/

        return null;
    }

    // have same code in packages/apps/AsusLauncher/src/com/android/launcher3/ResCustomizeConfig.java
    private static String getWallpaperFilePathFromADF(String wallpaperName) {
        if (getVersatilityPath() == null) {
            return null;
        }

        File[] fileList = getFileStartsWith(getWallpaperFolderPath(), wallpaperName, true);

        if (fileList == null) {
            if (DEBUG) Log.v(TAG, "ADFDefaultWallpaperFilePath NOT found!");
            return null;
        } else if (fileList.length > 0) {
            if (fileList.length > 1) {
                if (DEBUG) Log.v(TAG, "ADFDefaultWallpaperFilePath may NOT UNIQUE in folder");
            }
            return fileList[0].toString();
        } else {
            return null;
        }
    }

    private static String[] getWallpaperListInOrder(Context context, final String xmlName, final String folderPath) {
        final String startTag = "string-array";
        final String startTagFieldName = "name";
        String startTagField = (isSupportDds() && isDdsPad(context)) ?
                "pad_default_wallpaper_names" :
                "default_wallpaper_names";
        final String itemTag = "item";

        ArrayList<String> rtn = new ArrayList<String>();
        File[] fileList = getFileStartsWith(folderPath, xmlName, true);
        if (fileList == null) {
            return null;
        }

        if(fileList.length > 0) {
            InputStream in = null;
            try {
                in = new BufferedInputStream(new FileInputStream(fileList[0]));

                XmlPullParser parser = Xml.newPullParser();
                parser.setFeature(XmlPullParser.FEATURE_PROCESS_NAMESPACES, false);
                parser.setInput(in, null);

                int type = parser.getEventType();
                while (type != XmlPullParser.END_DOCUMENT) {
                    if (DEBUG) Log.v(TAG, "parser.getName() = "+parser.getName()+", parser.getEventType()= "+parser.getEventType());
                    if (startTag.equals(parser.getName()) && parser.getEventType() == XmlPullParser.START_TAG) {

                        if (DEBUG) Log.v(TAG, "parser.getAttributeValue(null, "+startTagFieldName+") = "+parser.getAttributeValue(null, startTagFieldName));
                        if (startTagField.equals(parser.getAttributeValue(null, startTagFieldName))) {

                            while (parser.nextTag() == XmlPullParser.START_TAG) {
                                parser.require(XmlPullParser.START_TAG, null, itemTag);
                                rtn.add(parser.nextText());
                                if (parser.getEventType() != XmlPullParser.END_TAG) {
                                    parser.nextTag();
                               }
                                parser.require(XmlPullParser.END_TAG, null, itemTag);
                            }
                       }
                    }
                    type = parser.next();
                    if (DEBUG) Log.v(TAG,"type = "+type);
                }
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (IOException e) {
               e.printStackTrace();
            } catch (XmlPullParserException e) {
                e.printStackTrace();
            } finally {
                if (in != null) {
                    try {
                        in.close();
                    } catch (IOException t) {
                        Log.w(TAG, "close fail ", t);
                    }
                }
            }

       }
        if (DEBUG) Log.v(TAG, "WallpaperListInOrder: " + rtn + ", xmlName= " + xmlName + ", folderPath= " + folderPath);
        return rtn.isEmpty() ? null : rtn.toArray(new String[rtn.size()]);
    }

    private static String getWallpaperFolderPath() {
        final String verPath = getVersatilityPath();
        return TextUtils.isEmpty(verPath) ? null : verPath + WALLPAPER_PATH;
    }

   private static String getLauncherResFolderPath() {
        return RES_CUSTOMIZE_ETC_ROOT_PATH;
    }

    private static boolean isDirectory(String path) {
        return TextUtils.isEmpty(path) ? false : new File(path).isDirectory();
    }

    private static String getVersatilityPath() {
        String resVersaFolderPath = RES_CUSTOMIZE_ROOT_PATH
                + "/"
                + SystemProperties.get("ro.config.versatility", RES_VERSA_DEFAULT_FOLDER_NAME).trim()
                + "/"
                + SystemProperties.get("ro.config.CID", "").trim();
        if (isDirectory(resVersaFolderPath)) {
            return resVersaFolderPath;
        }

        resVersaFolderPath = RES_CUSTOMIZE_ROOT_PATH + "/" + RES_VERSA_DEFAULT_FOLDER_NAME;
        if (isDirectory(resVersaFolderPath)) {
            return resVersaFolderPath;
        }

        return null;
    }

    private static File[] getFileStartsWith(final String folderPath, final String startsWithName, final boolean ignoreCase) {
        if (!isDirectory(folderPath)) {
            return null;
        } else {
            File folder = new File(folderPath);
            FilenameFilter textStartsWithFilter = new FilenameFilter() {
                @Override
                public boolean accept(File dir, String filename) {
                    filename = ignoreCase ? filename.toLowerCase() : filename;
                    String findName = ignoreCase ? startsWithName.toLowerCase() : startsWithName;

                    if (filename.startsWith(findName)) {
                        Log.v(TAG, "find: " + filename + ", getFileStartsWith: " + startsWithName + ", ignoreCase= " + ignoreCase + ", find in folder: " + folderPath);
                        return true;
                    } else {
                        return false;
                    }
                }
            };

           return folder.listFiles(textStartsWithFilter);
        }
    }

    public static boolean isSupportDds() {
        return SystemProperties.getInt("persist.sys.padfone", 0) == 1;
    }

    public static boolean isScreenSizePad(int screenSize) {
        return screenSize > Configuration.SCREENLAYOUT_SIZE_NORMAL;
    }

    public static boolean isDdsPad(Context context) {
        return isSupportDds() && isScreenSizePad(getScreenSize(context));
    }

    public static int getScreenSize(Context context) {
        if (context == null) return -1;
        return context.getResources().getConfiguration().screenLayout & Configuration.SCREENLAYOUT_SIZE_MASK;
    }

    /**
     * Check if the wallpaper-set is for zenfone2
     * @param context
     * @return false for default,

     *         or true if zenfone2_sp is the field of START_TAG default_wallpaper_set
     */
    public static boolean isZf2List() {
        final String xmlName = "default_wallpaper_list.xml";
        final String folderPath = getLauncherResFolderPath();
        final String startTag = "string";
        final String startTagFieldName = "name";
        final String startTagField = "default_wallpaper_set";
        final String desiredString = "zenfone2_sp";

        File[] fileList = getFileStartsWith(folderPath, xmlName, true);
        if (fileList == null || fileList.length == 0) {
            return false;
        }
        if(fileList.length > 0) {
            InputStream in = null;
            try {
                in = new BufferedInputStream(new FileInputStream(fileList[0]));

                XmlPullParser parser = Xml.newPullParser();
                parser.setFeature(XmlPullParser.FEATURE_PROCESS_NAMESPACES, false);
                parser.setInput(in, null);
                int type = parser.getEventType();
                while (type != XmlPullParser.END_DOCUMENT) {
                    if (startTag.equals(parser.getName()) && parser.getEventType() == XmlPullParser.START_TAG) {
                        if (startTagField.equals(parser.getAttributeValue(null, startTagFieldName))) {
                           return desiredString.equals(parser.nextText());
                        }
                    }
                    type = parser.next();
                }
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            } catch (XmlPullParserException e) {
                e.printStackTrace();
            } finally {
                if (in != null) {
                    try {
                        in.close();
                    } catch (IOException t) {
                       Log.w(TAG, "close fail ", t);
                    }
                }
            }

        }
        return false;
    }
    // ------------------------------------------------------------------------
    // FIELDS
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // INITIALIZERS
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // CONSTRUCTORS
    // ------------------------------------------------------------------------

    // ------------------------------------------------------------------------
    // METHODS
    // ------------------------------------------------------------------------

}

//add by youxiaoyan for SystemUI 20160309 -e