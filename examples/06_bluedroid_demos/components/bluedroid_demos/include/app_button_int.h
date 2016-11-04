#include "prf_defs.h"
#include "bt_prf_sys.h"
#include "bt_types.h"

#if (BUT_PROFILE_CFG)

/// Messages for Device Information Service Server
enum
{
    ///Add a BUTTON instance into the database
    BLE_BUT_CREATE_DB_REQ_EVT = BT_PRF_SYS_EVT_START(PRF_ID_BUT_LE),
    ///Send key value confirm to APP so stable values can be erased
    ///if correctly sent.
    BLE_BUT_VAL_SEND_CFM_EVT,
    ///Set the value of an attribute
    BLE_BUT_SET_CHAR_VAL_REQ_EVT,
	
    ///Start the button notify Service Task - at connection
    BLE_BUT_ENABLE_REQ_EVT,

    /// Inform the application that the profile service role task has been disabled after a disconnection
   	BLE_BUT_DISABLE_IND_EVT,
   	/// Inform the application that the profile service has been reiceivd the charateristic write commamd from Client
	BLE_BUT_CHAR_WRITE_IND_EVT,
    ///Error indication to Host
    BLE_BUT_ERROR_IND_EVT,
};

/// Parameters of the @ref KEY_CREATE_DB_REQ message
typedef struct
{
    ///Database configuration
    uint16_t features;
}tBUT_CRT_DB_REQ;

/// Parameters of the @ref	KEY_CREATE_DB_CFM message
typedef struct
{
    ///Status
    uint8_t status;
}tBUT_CRT_DB_CFM;

///Parameters of the @ref key_CFG_INDNTF_IND message
typedef struct
{
    ///Connection handle
    uint16_t conhdl;
    ///Stop/notify/indicate value to configure into the peer characteristic
    uint16_t cfg_val;
    /// characteristics
    uint8_t char_code;
}tBUT_CFG_NTF_IND;


/// Parameters of the @ref KEY_SET_CHAR_VAL_REQ message - shall be dynamically allocated
typedef struct 
{
    /// Characteristic Code
    //uint8_t char_code;
  	uint8_t	conhdl;
    uint8_t key_val_len;
    uint8_t key_val[2];
}tBUT_SND_CHAR_VAL_REQ;

/// Parameters of the @ref KEY_ENABLE_REQ message
typedef struct
{
    ///Connection handle
    uint16_t conhdl;
    /// security level: b0= nothing, b1=unauthenticated, b2=authenticated, b3=authorized; b1 or b2 and b3 can go together
    uint8_t sec_lvl;
    ///Type of connection
    uint8_t con_type;
}tBUT_ENABLE_REQ;

///Parameters of the @ref KEY_VAL_SEND_CFM message
typedef struct
{
    ///Connection handle
    uint16_t conhdl;
    ///Status
    uint8_t status;
}tBUT_VAL_SND_CFM;


/// Parameters of the @ref KEY_DISABLE_IND message
typedef struct 
{
    ///Connection handle
    uint16_t conhdl;
}tBUT_DISABLE_IND;

typedef union
{
	uint16_t conhdl;
	tBUT_CRT_DB_REQ 		but_crt_db_req;
	tBUT_CRT_DB_CFM 		but_crt_db_cfm;
	tBUT_CFG_NTF_IND		but_cfg_ntf_ind;
	tBUT_SND_CHAR_VAL_REQ	but_snd_char_val_req;
	tBUT_ENABLE_REQ			but_enable_req;
	tBUT_VAL_SND_CFM		but_val_snd_cfm;
	tBUT_DISABLE_IND		but_disable_ind;
}tBUT_PRF_MSG;



BOOLEAN ble_but_prf_hdl_event(prf_hdr_evt_t *msg_data);

void ble_but_prf_disable(void);



#endif	///BUT_PROFILE_CFG



