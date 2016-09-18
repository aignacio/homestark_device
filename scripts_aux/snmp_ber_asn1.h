#ifndef __SNMP_BER_ASN1_H__
#define __SNMP_BER_ASN1_H__

#include <stdbool.h>
/**
 * @brief Primitives data types of ANS.1 encoding
 *
 */
#define ASN1_PRIM_INTEGER    0x02
#define ASN1_PRIM_OCT_STR    0x04
#define ASN1_PRIM_NULL       0x05
#define ASN1_PRIM_OID        0x06
#define MAX_COMMUNITY_STRING 0x80 // 128 bytes
/**
 * @brief Complex data types of ANS.1 encoding
 *
 */
#define ASN1_CPX_SEQUENCE 0x30
#define ASN1_CPX_GET_REQ  0xA0
#define ASN1_CPX_NEXT_REQ 0xA1
#define ASN1_CPX_GET_RESP 0xA2
#define ASN1_CPX_SET_REQ  0xA3

/** @brief value of the version field for the SNMPv1 */
#define SNMP_VERSION_1					0
/** @brief value of the version field for the SNMPv2c */
#define SNMP_VERSION_2C					1
/** @brief value of the version field for the SNMPv3 */
#define SNMP_VERSION_3					3
/** @brief Decode the initial sequence type */
#define check_seq(x) (x == ASN1_CPX_SEQUENCE ? 1 : 0)



/************************************************************************************************************/

#define DEBUG_SNMP
#ifdef DEBUG_SNMP
#define debug_snmp(fmt, args...) printf("\n[SNMP] "fmt, ##args)
#else
#define debug_snmp(fmt, ...)
#endif

typedef enum resp_con{
   FAIL_CON,
   SUCCESS_CON,
} resp_con_t;

typedef struct {
    uint8_t         request_type;
    uint8_t         response_type;
    uint8_t         request_id[5];
    uint8_t         error_status;
    uint8_t         error_index;
    uint16_t        var_name;
    uint16_t        var_value;
} snmp_t;

#endif

/************************************************************************************************************/
// resp_con_t generate_snmp_task(unsigned char *pdu_snmp[], uint8_t pdu_type);
// resp_con_t decode_ber_asn1(unsigned char *data[]);
// void decode_asn1_oct(unsigned char *snmp_oct[], uint8_t length, char *com_string);
// uint16_t decode_asn1_integer(unsigned char *snmp_int[], uint8_t length);
// void decode_req_id(unsigned char *pdu_snmp[], char *req_id);

int pow(int base, int exp);

/** @brief Encode integer into ASN.1
 *
 * 		Encode an integer value into ASN.1 format acordding to BER rules
 *
 *  @param [in]  integer_data Integer 32-bit value to be encoded
 *
 *  @retval encoded_value Pointer to the begin of data encoded [type][len][data][...]
 *
 **/
uint8_t *encode_asn1_integer(uint32_t *integer_data);

/** @brief Decode integer into ASN.1
 *
 * 		Decode an integer value into ASN.1 format acordding to BER rules
 *
 *  @param [in]  data_encoded Pointer to the data to be decoded
 *
 *  @retval integer_data Pointer to the address of the value converted
 *
 **/
uint32_t decode_asn1_integer(unsigned char *data_encoded[]);