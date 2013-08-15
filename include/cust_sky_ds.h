#ifndef __CUST_SKY_DS_H__
#define __CUST_SKY_DS_H__


/*****************************************************
    SKY Android �� ���� �������
    Feature Name : T_SKY_MODEL_TARGET_COMMON
******************************************************/
#ifdef T_SKY_MODEL_TARGET_COMMON

#endif /* T_SKY_MODEL_TARGET_COMMON */


/* ######################################################################### */
/*****************************************************
    SKT/KT ���� �������
    Feature Name : T_SKY_MODEL_TARGET_WCDMA
******************************************************/
#ifdef T_SKY_MODEL_TARGET_WCDMA
/************************************************************************************************************************
**    1. Related 3G-connection
************************************************************************************************************************/

/* 
 - Phone Interface�� ���� ���ϴ� APP�� ���Ͽ� AIDL�� �߰�
 - aidl ���� : ISkyDataConnection.aidl
 - �������̽� ���� : MMDataConnectionTracker.java
 - �߰� ���� ���� : DataPhone.java, Phone.java , SkyDataConInterfaceManager.java
 - aidl ���� �߰� : service_manager.c�� .aidl �߰�
 - make ���� ���� : android/framework/base/Android.mk ����
 - telephony/java/com/android/internal/telephony/ISkyDataConnection.aidl �߰�
*/
#define FEATURE_SKY_DS_ADD_DATA_AIDL

/* 
 - startUsingNetworkFeature���� Reconnect ȣ��� Fail�� �߻��Ͽ��� Phone.APN_REQUEST_STARTED�� �����Ͽ� Application���� ȥ���� ������
 - reconnect ���н� APN_REQUEST_FAILED�� �����ϵ��� ����
*/
#define FEATURE_SKY_DS_BUG_FIX_STARTUSINGNETWORKFEATURE

/*
- ���������� dataConnectionChanged Action���� ����Ǵ� Network Info�� isAvailable ���� false�� ����Ǿ� �ִ� ��� �߻�
- �� ������ 1.sim, 2.roaming, 3.���� ����, 4.PDP ���� ���� (Default Enable , DISCONNECTED)�� Check�ϴµ� 
   4�� ������ ��� NATE ��� PDP�� �ٽ� Activate�� ��Ű�� ����� ����� ���Ǹ� ���� �����Ƿ� ���� ���� 
*/
#define FEATURE_SKY_DS_CHANGE_IN_AVAILABLE_CHECK_IN_STARTUSINGNETWORK

/*
 - WIFI �� 3G ����� default router�� 2�� ������ ���� ����
 - WIFI, Data ���� ���¸� ��� Ȯ�� �ϱ� ���Ͽ� dhcpclient���� add route�ϴ� ������ framework�� �̵� (ConnectivityService)  
 - 3G Data�� WIFI ����� ���� 3G Default Network ����
 - default route add/remove function MobileDataStateTracker.java ���� ó���ϵ��� ����.
 - 3G connected event broadcast �� �� ��config ������ interface up ���� �ʴ� ������ broadcast ���� interface up check. 
   (�������� ���¿��� �ʱ�ȭ �� ���� �ڵ� �ٿ�ε� ���� �ʴ� ����.)
 - 3G ���� �Ŀ��� config �� ������ ���� �� interface down ���� ����Ǿ� check �ϴ� �κ� �߰�. (tethering ���� ����)
 -[KTF] remove dns route �������� �ʴ� ������ mIPv4InterfaceName, mIPv6InterfaceName �� disconnect ���� null �� ����� �κ� ����. 
 - EF45K ICS : ifc_utils.c ���� property set �� get �ؼ� setting �� ���� üũ �κи� �����.
*/
#define FEATURE_SKY_DS_CHANGE_DEFAULT_ROUTE_FOR_MOBILE


/*
 - Fast Dormancy ��� ����
 - �ó����� : LCD ON�� ��Ʈ��ũ���� �������� �޽����� dormant ���� �Ǵ�, LCD OFF�� 10�� �� Dormant ����
 - aArm : LCD ON/OFF ������ mArm���� �����ϵ��� ����
 - mArm : FEATURE_SKY_DS_FAST_DORMANCY ����
*/
#define FEATURE_SKY_DS_FAST_DORMANCY

/*
  - PDP Fail �� loggable fail cause �̸� logging ���涧 �ܸ� �״� ������ isEventLoggable() ���� �׻� false �����ϵ�����.
*/
#define FEATURE_SKY_DS_AVOID_FATAL_EXCEPTION

/*
  - �����迡�� pdp connection fail �� retry timer �����ϸ鼭 ������ �̵��ÿ� ������ timer ������ retry �Ͽ� ������ �ȵǴ°����� 
    ���̴� ����߻��Ͽ� screen on ���¿����� timer ������Ű�� �ʰ�, off->on �� ��� �ٷ� try �ϵ��ϼ���
*/  
#define FEATURE_SKY_DS_IMMEDIATE_SETUP

/*
  - permanent fail �� alert pop-up �� data disable ��Ŵ
   => data enable ���� �����ϰ� notification / pop-up ������. 
*/
#define FEATURE_SKY_DS_PDP_REJECT_POPUP

/*
- no service event �� �߻��� ��� ���� data ������� �ʰ� disconnected �� broadcast �Ǿ� default route �����ǰ� 
   �ٷ� in service ���ԵǸ� �Ʒ������δ� data ����Ǿ� ������ �������� ������� ���� ������ ���̴� ���� 
- dataconnectiontracker.java , BSP ���� �ּ�ó���Ǿ� �ʿ� ���� ��� ����. 
-> ICS ������ phonebase.java �� PROPERTY_OOS_IS_DISCONNECT �� �ش� ���� ó���Ǿ� default���� false �� ������. 
*/
#define FEATURE_SKY_DS_NO_SERVICE_BUG_FIX

/*
-  RadioTech �� unknown ���� ���� ��� networkInfo�� available �� false �� �ȴ�.
-  connected ���¿��� �̷��� �Ǹ� browser ���� network ����� �� ���ٴ� pop-up �߻��Ǹ鼭 
- �������� �ε�Ǵ� ������ �߻��ȴ�. 
- �������� : MobileDataStateTracker.java    
- networkInfo isAvailable �κ��� KT App �䱸�������� ���� ������ �ϰ�, CONNECTED ���� �������¿���
   UNKNOWN_TECH �÷� Indicator ������� ���� ������.  
- �������� : TelephonyRegistry.java
*/
#define FEATURE_SKY_DS_AVOID_UNKNOWN_RADIO_TECH


/*
- ACTION_ANY_DATA_CONNECTION_STATE_CHANGED intent �� ���޵��� �ʴ� ��찡 �߻��Ͽ�
   intent broadcast(notifyDataConnection) �� connectivityservice �� update �� �Ǿ����� üũ.
 - dataconnectiontracker.java mmdataconnectiontracker.java
*/
#define FEATURE_SKY_DS_ANY_DATA_INTENT_RECOVERY


/*
- datausage �޴����� background data ���� �� for loop �� ���� UID ���� ip table �� set �� �־� 
   app ���� �ð� �� ���� ���� anr �߻� �� background data ���� ���� �� booting �� system ���� 
   anr �߻��ϴ� ���� ����   =>�� UID ���� event �� ó���ǵ��� ��.
- android_filesystem_config.h  �� Define �� UID �� system UID �� ����. 
- system/bin/iptables �� system �������� �Ǿ� ������ ip6tables �� shell �� �Ǿ� �վ� system ���� ����.
   -NetworkPolicyManagerService.java
*/
#define FEATURE_SKY_DS_BACKGROUND_RESTRICT_BUG_FIX

/*
- system/bin/iptables �� system �������� �Ǿ� ������ ip6tables �� shell �� �Ǿ� �վ� system ���� ����.
   -android_filesystem_config.h
*/

#define FEATURE_SKY_DS_IP6TABLE_UID_BUG_FIX

/*
- data registration statue query �� fail �߻��ϸ� data service state �� no service, radio tech �� none ���� ó���Ǵ� ������ 
   ���� ���� newSS �� �����Ͽ� ���� response fail �߻��� ���� �� �����ϵ��� ��. 
- GsmServiceStateTracker.java
*/
#define FEATURE_SKY_DS_DATA_REGISTRATION_QUERY_FAIL_RECOVERY

/*
- MMS send �� �׻� secondary dns address �� dns query�� ������ ���� ���� ����
*/
#define FEATURE_PS_WRITE_PID_DNS_BUF_FIX

#define FEATURE_SKY_DS_IP6TABLE_CMD_BUG_FIX

/************************************************************************************************************************
**    2. Related MENU / UI
************************************************************************************************************************/

/*
 - APN Settings Menu�� Hidden Code(##276#7388464#)�� ���� �� �� �ֵ��� ����
*/
#define FEATURE_SKY_DS_ADD_APN_SETTING_HIDDEN_CODE

/*
 - APN �޴� ����� �������� �̵� (DS1_DATA_REMOVE_APN_SETTING_MENU ����)
 - default apn�� ���Ͽ� ���� �Ұ� �ϵ��� ����
 - Hidden Code�� �Ϲ� ����� �޴� �����Ͽ� �����ϵ��� ����
  - data disable-> enable ��ų ��� default apn ���� Ȯ���ϰ�, ����� ��� reset
*/
#define FEATURE_SKY_DS_PREVENT_EDIT_DEFAULT_APN

/*
- easy setting ��� �߰���, socket data moe �����ϴ� �κп��� intent broadcast ����� ��.  
- SKT �� KT �԰� ���̷� data mode setting �ϴ� �κ� ����.
*/
#define FEATURE_SKY_DS_EASY_SETTING

/* 
 - hidden menu���� RRC version ���ÿ� ���� category ������ �ǵ��� ������.
 - HSUPA category�� NV ó���� �Ǿ� ���� �ʾƼ� �߰���.
 - R4 only ���� �� HSDPA category / HSUPA category �׸� disable�� ������.
 - R5(HSDPA) ���� �� HSDPA category enable / HSUPA category disable�� ������.
 - R6(HSDPA) ���� �� HSDPA category disable / HSUPA category enable�� ������.
 - HSUPA�� �������� �ʴ� Ĩ�� ���, R6 ���� �� ���� ���µǹǷ� rrc version �������� R6�� �ݵ�� �����ؾ� ��. 
*/
#define FEATURE_SKY_DS_HSUPA

/* 
 - R7(HSPA) ���� �� HSDPA category enable / HSUPA category enable �ǵ��� ����. 
*/
#define FEATURE_SKY_DS_HSPA


/* 
  - TCP Buffer size ���� 
  - system/core/rootdir/nit.rc
*/
#define FEATURE_SKY_DS_LTE_TCP_BUFFER_CHANGE



/************************************************************************************************************************
**     3. CTS / PortBridge / DUN / Log /vpn
************************************************************************************************************************/
#define FEATURE_SKY_DS_ATFWD_PROCESS

/*
- Data Manager ���� ó��. 
- AT$SKYLINK command �� data manager �����Ű��, 
- /dev/pantech/close file �� ������ �����Ǹ� data manager �� ����� ������ ó���Ѵ�. 
-/port_bridge/ , skydunservice.java
*/
#define FEATURE_SKY_DS_DATAMANAGER 

/*
 - ��ȭ���� ���� �� ����/���� �� toast�� ����/���� �˸�
 - notification ������ ���� �� �������� �˸�
 - port_bridge���� SkyDunService.java���� ui ó���� �ϱ� ���ؼ� DUN_EVENT_RMNET_DOWN�� ��쿡�� dun_disable_data_connection()���� dun file�� DUN_INITIATED�� write ��.
 - port_bridge���� SkyDunService.java���� ui ó���� �ϱ� ���ؼ� DUN_EVENT_RMNET_UP�� ��쿡�� dun_enable_data_connection()���� dun file�� DUN_END�� write ��.
 - 3G ���Ӱ� ��ȭ������ ���ÿ� �Ͼ ���, DUN_STATE_CONNECTED ���¿��� 3G ������ ���� �Ͼ ���, ��ȭ������ ������� �ʰ�, UI�� ���� ���� �ȴ�. 
   �̸� �ذ��ϱ� ���ؼ� DUN_STATE_CONNECTED���� DUN_EVENT_RMNET_UP �� ���, ��ȭ������ �����Ѵ�.
*/
#define FEATURE_SKY_DS_RELATED_DUN_UI

/*
  - USB tethering ���� wifi ���� �� ��� wifi �켱 ����ϵ��� config.xml �� tethering.java �� ���� �� �߰�. 
*/
#define FEATURE_SKY_DS_WIFI_USB_TETHERING

/*
- Ư�� VPN ���� ���� �ȵǴ� ���� (���� : android ��  SSL VPN �� Cisco VPN ������)
- external\mtpd\L2tp.c �� kernel config ( kernel\arch\arm\config\msm8660-EF34K_deconfig ���� �̹� define�� ������ �ּ�ó���ϰ� y�� ���� )
*/
#define FEATURE_SKY_DS_VPN_FIX

/*
- CTS testTrafficStatsForLocalhost test �� ���� kernel config �� CONFIG_UID_STAT=y �� ����. 
*/
#define FEATURE_SKY_DS_CTS_LOCALHOST

/*
-  usb tethering/wifi hotspot �� google dns ���� ������� �Ϻ� ����Ʈ ������� �ʴ� ���� 
- ConnectivityService.java  tethering.java
*/
#define FEATURE_SKY_DS_SET_TETHERED_DNS

/*
�״��� ���� �� WIFI ����� 3G ������ ������� �ʴ� ����
*/
#define FEATURE_SKY_DS_TETHERED_BUG_FIX


#define FEATURE_DS_DEACTIVATE_PENDING_BUG_FIX

/************************************************************************************************************************
**     4. VT
************************************************************************************************************************/
/*
- VT ���� , CS VT control interface �� sdio_vt.c ����.
*/

#define FEATURE_PANTECH_VT_SUPPORT

#define FEATURE_PANTECH_VT_SUPPORT_KT

#define FEATURE_PANTECH_VT_SUPPORT_QMI

#define FEATURE_PANTECH_VT_SUPPORT_QMI_KT

#define FEATURE_PANTECH_VT_SUPPORT_QMI_CALL_TYPE //CSVT call_type �߰� 
/*
- Qmi ������ ���� �� �Ŀ� �Ʒ� ���뿡 ���� ������ �ڵ尡 ���� ���� �ʾ� ������.
-----------------------�Ʒ� ----------------------------------
- NV_NOTACTIVE�� ���� ����� �ʿ��� �׸���.
- NV_ACTIVE �׸��� �𵩿��� Sky_Nv_Protocol���� �ʱ�ȭ�� ������, 
- NOTACTIVE�� �ʱ�ȭ�� ���� �ʾ� READ �Ҽ� ����.  
*/  

#define FEATURE_SKY_DS_GETNV_QVP_DEFAULT


#endif/* T_SKY_MODEL_TARGET_WCDMA */


/* ######################################################################### */


/*****************************************************
    SKT �� �������
    Feature Name : T_SKY_MODEL_TARGET_SKT
******************************************************/
#ifdef T_SKY_MODEL_TARGET_SKT
#ifdef T_SKY_MODEL_TARGET_KT
#error Occured !!  This section is SKT only !!
#endif

#endif/* T_SKY_MODEL_TARGET_SKT */


/* ######################################################################### */
/*****************************************************
    KT �� �������
    Feature Name : T_SKY_MODEL_TARGET_KT
******************************************************/
#ifdef T_SKY_MODEL_TARGET_KT
#ifdef T_SKY_MODEL_TARGET_SKT
#error Occured !!  This section is KT only !!
#endif

/************************************************************************************************************************
**    1. Related 3G-connection
************************************************************************************************************************/

/*
 - 3G(GPRS) Data Suspend/Resume �Լ�
 - GSMPhone�� disableDataConnectivity/enableDataConnectivity�� PLMN ���� �˻��� Ȱ���ϸ� ������ �־� ���ο� �Լ� �߰�
 - getDataConnectionState() ���� connected�� �ƴϸ� ���� disconnected �� return �ؼ� connecting ���¿��� �����˻� ����Ǵ� ������ connecting �߰�.
*/
#define FEATURE_KT_DS_SUSPEND_RESUME_FUNC

/*
 -KT 3G Data ���� �ó����� ���� =>> system property ���� db �� SOCKET_DATA_CALL_MODE �� �����ؼ� ����. kaf oem api 0.9.0 �� default ���� popup ���� �䱸��.
- setup alert popup ���� ���� ���ý� data mode setup ȭ������ �̵�.
- data mode setup ȭ���� skydatamodesettings.java �� ������. => \packages\apps\Phone\src\com\android\phone\settings.java �� ����.
=> 2011.10.21 android �����ϴ� SOCKET_DATA_CALL_ENABLE �� ����. 
*/
#define FEATURE_KT_DS_DATA_SETUP

/*
 - data/dun setup �������� üũ�� KT PS reject cause üũ �� toast. 
 - ��Ʈ��ũ ������� ��쿡�� toast ó���ϰ� �߽Žõ��ؾ���. skydunservice.java
*/
#define FEATURE_KT_DS_PS_REJECT

/*
 �ܸ� ���� �޴��� "�� APN"(default.ktfwing.com) �߰� ����, LMS �޽��� �߽� �� (WIFI ON/3G ON) APN Ȯ�� �� �⺻ APN(alwayson-r6.ktfwing.com)�� �����ϰ� �ִ� ���� ����.
*/
#define FEATURE_KT_DS_APN_MMS_BUGFIX

/*
 wifi enable ���¿��� wifi disconnect/connect �� 3G ���� �˾��� ���� �߻��Ͽ� 
 wifi ���� �ð��� ����Ͽ� �˾� �߻��� 3�� ������ ��Ŵ. wifi disable ���´� ������ ���� ����.   
*/

#define FEATURE_KT_DS_WIFI_3G_POPUP_DELAY

/*
 wifi on, 3G on ���¿��� mms ���۽� 1���� ���� ���� ���� ����. 
 startusing ����ϴ� ������  MMS ���۽� ���� Ÿ�̸� �۵��Ͽ� 1���� �����ϴ� �κ� ����. 
*/
#define FEATURE_KT_DS_DISABLE_TIMER_IN_MMS

/*
- data mode on/off �� lte �� attach,detech �ϵ��� pref mode ���泻�� �߰�.
- mmdataconnectiontracker.java
*/
#define FEATURE_KT_DS_LTE_DATA_SETUP

/*
- KAF Req. startUsingNetworkFeature() �� feature �� "KT_Internet" ���� ��û�� data ���� ���� �� ���¸� ��������. 
- ConnectivityService.java
*/
#define FEATURE_KT_DS_KAF_CONNECTIVITY

/* KT �䱸 ���׿� �� ���Ͽ� MSS size 1410 ����( MTU1450���� ���� ) */
#define FEATURE_KT_DS_CHANGE_MTU

#define FEATURE_SKY_DS_CNE_DISABLE 
/*
 - CS Call �߿��� PS Data�� Block�Ͽ� Call Drop�� ���� �Ѵ�.
*/
#define FEATURE_KT_DS_VOICE_CALL_PROTECTION_IN_MULTI_RAB

/*
- Data mode disable �� ��� mms network info �� isAvailable �� false �� return 
- MMS ��û����. 
*/
#define FEATURE_KT_DS_MMS_UNAVAILABLE_ON_DATA_DISABLE


#define FEATURE_SKY_DS_MULTIPLE_PARTIAL_RETRY_BLOCKING

/*
- ISkyDataConnection�� 3rd parth app���� ������ ��뷮 �ʰ� ������ �Ǵ��� �� �ִ� API �߰�
*/
#define FEATURE_SKY_DS_NET_OVERLIMIT_API

/************************************************************************************************************************
**    2. Related MENU / UI
************************************************************************************************************************/
/*
  packages\apps\Phone\src\com\android\phone\settings.java �� network_settings.xml ���� ó���ϵ��� �����. 
=>   2011.10.21 MobileNetworkSettings.java / mobile_network_settings.xml �� �����. 
*/
#define FEATURE_KT_DS_ADD_ALWAYSON_MENU


/*
  - Lab Test Menu�� vt emulator �޴� �߰��Ͽ� ext 324 NV ������� �߰�
*/
#define FEATURE_KT_DS_VT_EMULATOR

/*
- lock ���¿��� incoming call ���ŵ� ���¿��� wifi ���� ����Ǿ� data pop ǥ�õǰ� ���� �����ϸ� lock ȭ�� ���̴� ����.
- telephonyintent �� ringcall start/end �߰��Ͽ� broadcast �ϸ� data popup���� ringing �̸� �����޴� ���Ը��ϰ���. 
- GsmCallTracker.java, TelephonyIntents.java, MMDataConnectionTracker.java
=> 2011.10. KAF �˼� ������ ����, �ó���������. pop-up ���¿��� incoming call �߻��ϸ� pop-up �ݰ� data ����. 
*/
#define FEATURE_KT_DS_POPUP_IN_RINGSCREEN_BUG

/* 
- Roaming �� data roaming enable uncheck �����̸� notification ������ �����ְ� �������� �ʵ��� �Ѵ�.
- ������ ���� �� ���̵��� ��, ���ý� ���� �޴��� �̵�. 
*/
#define FEATURE_KT_DS_ROAMING_SETUP


/************************************************************************************************************************
**     3. CTS / PortBridge / DUN / Log
************************************************************************************************************************/
/*
: KT OTA command ó�� "AT*KTF*OPENING" ./port_bridge/ , skydunservice.java
*/
#define FEATURE_KT_DS_EIF_OTA 

#define FEATURE_KT_DS_ATFWD_COMMAND

/*
  - dun ������¸� mmdataconnectiontracker.java ���� �����ϰ� state �� return �Ѵ�.
  => sky feature ���� KT feature �� ����. 
*/
#define FEATURE_KT_DS_DUN_SERVICE


/************************************************************************************************************************
**     4. VT
************************************************************************************************************************/

/*
- KT ������ȭ �ܸ� �԰� disconnect cause �߰�, qcril ������ undefine �� �ָ� �ȴ�. 
- local ringback tone ���� call progress info(#1,#2,#3,#8) üũ �� �߰�. 
*/
#define FEATURE_PANTECH_VT_SUPPORT_KT

#endif/* T_SKY_MODEL_TARGET_KT */


/************************************************************************************************************************
** ������ feature
************************************************************************************************************************/

/*  
#define FEATURE_SKY_DS_PRESERVATION_WAKEUP_BUG_FIX
=> FEATURE_SKY_DS_NO_SERVICE_BUG_FIX �� ����. 
- Preservation ���¿���  RA update �߿� rrc abort �� limited event ���� �� ���� Preservation �������� ���ϴ� ���� ���� 
*/

/*  
#define FEATURE_SKY_DS_CNE_DISABLE 
 => CNE ������. 
 - 2030 �������� CNE enable �Ǿ� WIFI����� 3G ������� �ʴ� ������ �߻�.
 - CNE �κ� �ӽ÷� �ּ� ó��. 
*/

/*
#define  FEATURE_SKY_DS_STABILITY_TEST
 =>  cust_sky.h �� FEATURE_PANTECH_STABILITY �� featuring ��. 
*/

/*
#defien FEATURE_SKY_DS_ADD_DATA_LOG
- framework �� �α� �߰� ����, ������. 
*/

/*
#define FEATURE_SKY_DS_CHANGE_MASTER_VALUE_TURE
 - mMasterDataEnabled�� false�� �Ǿ� Dataȣ�� �õ� ���� ���ϴ� ���� ����
 - ������ ��ư� mMasterDataEnabled�� ��� eclair ���� �� ���� �ǹ̰� ���� Dataȣ �õ��� �ش� Value üũ ���� ���� 
   =>3G ���� ���̳� �ι� ���� ���� �ݿ��Ϸ��� ������, ���ܽ� MMS �߽� ������ ������ true�� �����ϵ��� ����.
*/

/*
#define FEATURE_SKY_DS_CSS_INDICATOR_BUG_FIX
- EF34K 1085 patch �� css indicator ó�� ������. 
- CSS Indicator ���� 0 ���� ���޵Ǿ� 
- DataServiceStateTracker.java �� ���ԵǾ� �ִµ� ����Ȯ�� �ʿ�.

*/

/*
#define FEATURE_SKY_DS_IDLE_PDL
==> System team ���� ó���ϱ�� ��. 
- AT*PHONEINFO command �� PDL command �����Ŵ. system servier�� command ����.
 -idle download support
*/

/*
#define FEATURE_KT_DS_DUN_BLOCKING_IN_CS_ONLY
  - CS only �� ��� DUN ���� �õ����� ���ϵ��� ��.
  - mmdataconnectiontracker.java ���� ps restricted �� ��� 
  gsm.net.psrestricted property �� 1�� ���ְ� skydunservice ���� �� ���� üũ�Ѵ�.
*/

/*
#define USB_TETHERING_ERROR_TEMP
- nativeDaemonConnector.java �� USB Tetehring ���� ���� ���� 1087 ���� ������ �������� temp ó�� ....
*/

/*
#define FEATURE_SKY_DS_END_DUN
 - ��ȭ������ UI���� ���� ���, RPC�� �̿��� ��ȭ������ ���������� ����
 - 3G ���� ������ ���� �� ��� �����.
 - ����, notification �������� ��ȭ������ ������ ��� ������ �� �ִ� �˾� �����Ͽ� UI���� ������ ��쿡�� �����.
 - framework ���� �����ؼ� mmdataconnectiontracker ���� commandsinterface api call �ϵ��� �����.
=> 2011.10.21 KT ������� ����. 
*/

/*
#define FEATURE_SKY_DS_DUN_TEST_MENU
 - Froyo �������� Tethering ����� �߰��Ǿ� ��ȭ ������ nettest �޴����� �����ؾ߸� ������ �� �ֵ��� ������.
 - \LINUX\android\pantech\apps\NetTest\src\com\pantech\app\nettest\DunTest.java �߰� 
 - \LINUX\android\pantech\apps\NetTest\res\layout\duntest.xml �߰� 
 - [kt] ��ȭ ���� �״��� ���� �������� ���� -  android\pantech\apps\nettest\AndroidManifest.xml ������ �ּ� ó�� 
=>2011.10.21 KT ������� ����
*/

/*
#define FEATURE_SKY_DS_DUN_USER_MODE 
 - ������ : QualcommSetting ���丮�� �ִ� ���ϵ��� user mode �� ������� �����Ƿ�, dun, sync manager, data manger, curi explore�� ������� ����.
 - DunService.java ��� LINUX\android\packages\apps\Phone\src\com\android\phone\SkyDunService.java�� �߰���.
 - SkyPhoneBroadcastReceiver.java ���� dun service start �ϰ�, Dun_Autoboot.java������ ���� start �ϴ� �κ��� ����.
 - QualcommSetting\AndroidManifest.xml���� dun service�� �����ϰ�, packages\apps\Phone\AndroidManifest.xml�� sky dun service �߰�
=> 2011.10.21 atfwd ó���� �����. 
*/

/*
#define FEATURE_SKY_DS_PORTBRIDGE_EXTERNAL
 - port_bridge(dun ����) ó�� ���� feature. ./port_bridge/ , skydunservice.java 
 - �ʱ� ���ý� dun_ext_smd_ctrl���� TIOCMGET�� ���� ������ ������ dun_monitor_ports�����尡 ���۵��� ����. (TIOCMGE���� ���� �����尡 ���� ����) 
 - dun_port_dataxfr_up �����尡 ������ �ʰ� ���鼭 CPU�� ��κ��� ������.
 - MODEM�� TIOCMGET������ �����Ǳ� ���� dun_monitor_ports �����尡 ���� �Ǹ� �ٽ� �����尡 ���� �ǰ� ����.
 => 2011.10.21 atfwd ���� ó���� �����.
*/

/*
#define FEATURE_SKY_DS_JAVA_CACHE
 - 3G OFF ���¿��� MMS ���۽� DNS ����  IP add  ����� NULL�� �Ѿ� ���� ���� �߻�. 
 - unknownhost�� ��� cache �� ������� �ʵ��� �ּ� ó��. 
*/

/*
#define FEATURE_KT_DS_SW_RESET_RELEASE_MODE_NO_DATA_POPUP

 - �ܸ� ���� �߻��� 3G ���� �˾�(���ý� �˾� ) �߻����� �ʵ��� ����. 
 mmdataconnectiontracker.java   SurfaceFlinger.cpp
*/

/*
- Mobile data ���� �� default route add �� fail �߻��ϸ� ip �� �ٽ� add ���ֵ���. 
- networkStateTracker.java���� teardown() �ϰ� �ٷ� reconnect()�ϰԵǸ� disconnect ���� �ʾ�. IP �� add ����.
- �������� : NetworkStateTracker.java 

#define FEATURE_SKY_DS_DEFAULT_ROUTE_RESTORE
*/

/*
- radio off event �߻��� ���(rild dead or lpm or rpc reset..etc) data disconnect ���Ѽ� radio on �� ��� ������ �ϵ��� �����ڵ� �߰�.
- mmdataconnectiontracker.java onRadioOff()
- FEATURE_KT_DS_DISCONNECT_CHECK ���� ���� feature �� ����. 
- EF45K ICS  �����Ǿ� feature ������. 
#define FEATURE_SKY_DS_DISCONNECT_CHECK
*/

/* 
 - TIMEOUT_INITIAL�� 1�ʷ� ����.
 - dhcpclient.c  Wi-Fi ������������ Wi-Fi �� �̰�.
#define FEATURE_SKY_DS_DHCP_DISCOVER_TIMER
*/

/*
- GB version���� startUsingNetworkFeature ���� �̹� connected �� service type�� ��� 
- dns configuration change ó���� network type �� ����Ͽ� �׻� mobile �� set �ؼ�
- private dns list �� pid �����ϵ��� �ʴ� ���� 
- connectivityService.java
- GB ���� �� ���� �ش系�� �����Ǿ� feature ����.
#define FEATURE_SKY_DS_DNS_CONFIG_BUG_FIX
*/

/*
- data disconnected �� ���� _test_dns_check �����ؼ� mms�����Ϸ��� �ϸ� inetaddress.getbyname() �ϸ� unknown host exception �߻�
- getaddrinfo.c ( LINUX\android\bionic\lib\netbsd\net\)
- IPv6 �� dns query �õ��ϴ� ������ feature ������. 
#define FEATURE_SKY_DS_DISABLE_TEST_DNS
*/

/*
- data connecting ���¿��� disable ��Ű�� service type disable ��Ű�� �ʴ� ���� 
- DataConnectionTracker.java
- GB ���� �� ���� �ش系�� �����Ǿ� feature ����.

#define FEATURE_SKY_DS_DISABLE_SERVICE_TYPE_BUG_FIX
*/

/*
- tether setting ���� oncreate �� �ʱⰪ update   
  tethersettings.java
  �����޴� R&R �����. 
#define FEATURE_SKY_DS_TETHER_STATE_INIT
*/

/*
 - �״��� ���� ���򸻿� ���� �ִ� URL�� Nexus One �����̹Ƿ� �ش� ���� ����(�������)
 - Wifi hotspot�� ���� ������ Wifi ���͸����� ����Ǿ� �־� ������.(�ѱ� ����, QE ������)
 - 20120227 Ȯ�� ��� ���� ���� �������� ����Ǿ� �ش� ���� ������.
#define FEATURE_SKY_DS_TETHERING_HELP
*/

/*
 - overylay ������ framework�� resource ��� 
 - ������� ����.
#define FEATURE_SKY_DS_RESOURCE 
*/

/* 
- Data ���� ICON default ���� 3G �� �����Ͽ� G �������� ������ �ʵ��� ����. 
- 20120227 �ҽ� �������� ���� ���� ����.
#define FEATURE_SKY_DS_DEFAULT_DATA_ICON
*/

/*
- Data Setup Fail �߻� �� WAITING_ALARM state ���� reconnect alarm intent ���� scanning ���·� set �ؼ� 
- data disable ���¿��� connecting ���� state �ö󰡴� ���� ����. 
- MMDataConnectionTracker.java
- 20120227 �ҽ� �������� ���� ���� ����.
#define FEATURE_SKY_DS_STATE_BUG_FIX
*/

/*
- Roaming �� intent "ACTION_ANY_DATA_CONNECTION_STATE_CHANGED"�� ���� ���� �ʾ� 
�ι����� ���� �� ���� �� notification�� �߻����� �ʴ� ���� ����.
- 20120227 MMDataConnectionTracker.java ����� ���� ���� ����. 
#define FEATURE_KT_DS_ROAMING_SETUP_BUG_FIX
*/

/*
 - EF18K IOT 1�� LMS 1, SBSM 8 ��û ���׿� ���� MMS TestMenu �߰� ��û�� ���� ##46632874# > �����Ͼ��忡 �߰� ��.
 - \LINUX\android\packages\apps\Settings\src\com\android\settings\skyhiddenmenu\KtHiddenMenu.java
 - \LINUX\android\packages\apps\Settings\res\xml\kt_hidden_menu.xml
 - \LINUX\android\packages\apps\Settings\res\values\strings_cp.xml
 - 20120227EF45K ���� OMA MMS ���뿡 ���� ����.
#define FEATURE_KT_DS_MMS_TESTMENU 
*/



/*
- DNS/gatway �ּҸ� üũ�Ͽ� ������ dataconnection�� teardown ��Ŵ.
=> EF45K ICS �� code ������
#define FEATURE_SKY_DS_BAD_IP_CHECK
*/

/*
- tearDwonData()�� �Ķ���Ͱ� �߸� �Ǿ� ������. 
- EF45K ICS �� �ڵ� ������.
#define FEATURE_SKY_DS_PARAMS_BUG_FIX
*/

/*
 - ����� ��Ʈ��ũ ���� �޴��� ������ ��� �޴� ���� 
 => EF45K ICS ���� data usage ����Ǿ�����, ����� �����.
#define FEATURE_SKY_DS_DATA_USAGE_MENU_BLOCKING
*/

/*
 - network interface, APN, socket, Concurrent(3G/WIFI) ���� �׽�Ʈ APP �߰�
 - WIFI Debug Screen �߰�
 - android/pantech/apps/skyLabTest ���� 
 - ���Ĵ� �������� �ʰ� apk�� ������.
#define FEATURE_SKY_DS_ADD_NETTEST
*/

/*
- �ι� ���� �� ���� �˾� ���̾�α� ���� Ȩ �̵� �� �����Խ� onResume ���� check box update �Ͽ� ���� üũ �ڽ����� 
  �����Ͽ��� ���̾�α� �������� �ʴ� ���� ���� 
#define FEATURE_SKY_DS_FIX_ROAM_CHECK_UI_BUG 
*/
/*
  - root process issue �� devices.c, init.rc, init.qcom.rc ���� ������ ����. 
  - cnd, netmgrd, port-bridge, ��Ť���
  - port_bridge �� ��� ������ code ���Ǿ�� �Ѵ�.
  - init.rc Ȥ�� init_�𵨸�.rc ���Ͽ��� /dev/pantech directory �� system �������� ����������Ѵ�. 
#define FEATURE_SKY_DS_CTS_ROOT_PROCESS
*/

/*
- qualcomm orignal code�߿� ������� �ʴ� �κ� ���� 
#define FEATURE_SKY_DS_NOT_USE_QUALCOMM_ORIGINAL
*/

/*
- vpn setting �޴� bug fix.
#define FEATURE_SKY_DS_VPN_SETTING_BUG
*/

/*
- SUID file finder ���� IP �� SUDI �� check�Ǿ� fail�Ǵ� ����
  80-N6956-2_A ���� ����
#define FEATURE_SKY_DS_CTS_SUID_CHECK
*/

/*
 - KTF �䱸���� : 3G Data�� Disable �Ǿ MMS ��/������ ���� ���� �ؾ� ��. 
 - Data Diable�� �����Ǿ� �־ MMS ���Ž� PDP�� �ø��� �ֵ��� ����
 - KT �䱸���� ���� : DATA Disable �� ��� MMS �ۼ��� �Ұ���. WIFI /DUN������ ��츸 feature �κ� ���. 
#define FEATURE_KT_DS_ALLOW_MMS_IN_DATA_DISABLE
*/

/*
 - IPv4 ������¿��� IPv6 max fail �� ��� data connection fail �� noti �Ͽ� connectivity�ʿ� data fail �� ���޵Ǵ� ���� 
 - mmdataconnectiontracker.java
#define FEATURE_KT_DATA_CONNECTION_FAIL_BUG_FIX
 */


#endif /* __CUST_SKY_DS_H__ */
