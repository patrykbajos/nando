#ifndef CMD_H
#define CMD_H

#include <cstdint>

enum
{
    CMD_NAND_READ_ID = 0x00,
    CMD_NAND_ERASE   = 0x01,
    CMD_NAND_READ    = 0x02,
    CMD_NAND_WRITE_S = 0x03,
    CMD_NAND_WRITE_D = 0x04,
    CMD_NAND_WRITE_E = 0x05,
    CMD_NAND_SELECT  = 0x06,
};

typedef struct __attribute__((__packed__))
{
    uint8_t code;
} Cmd;

typedef struct __attribute__((__packed__))
{
    Cmd cmd;
    uint32_t addr;
    uint32_t len;
} EraseCmd;

typedef struct __attribute__((__packed__))
{
    Cmd cmd;
    uint32_t addr;
    uint32_t len;
} ReadCmd;

typedef struct __attribute__((__packed__))
{
    Cmd cmd;
    uint32_t addr;
} WriteStartCmd;

typedef struct __attribute__((__packed__))
{
    Cmd cmd;
    uint8_t len;
    uint8_t data[];
} WriteDataCmd;

typedef struct __attribute__((__packed__))
{
    Cmd cmd;
} WriteEndCmd;

typedef struct __attribute__((__packed__))
{
    Cmd cmd;
    uint32_t chipNum;
} SelectCmd;

enum
{
    RESP_DATA   = 0x00,
    RESP_STATUS = 0x01,
};

typedef enum
{
    STATUS_OK        = 0x00,
    STATUS_ERROR     = 0x01,
    STATUS_BAD_BLOCK = 0x02,
    STATUS_WRITE_ACK = 0x03,
} StatusData;



typedef struct __attribute__((__packed__))
{
    uint8_t makerId;
    uint8_t deviceId;
    uint8_t thirdId;
    uint8_t fourthId;
} ChipId;

typedef struct __attribute__((__packed__))
{
    uint8_t code;
    uint8_t info;
    uint8_t data[];
} RespHeader;

typedef struct __attribute__((__packed__))
{
    RespHeader header;
    ChipId nandId;
} RespId;

typedef struct __attribute__((__packed__))
{
    RespHeader header;
    uint32_t addr;
} RespBadBlock;

typedef struct __attribute__((__packed__))
{
    RespHeader header;
    uint32_t ackBytes;
} RespWriteAck;

#endif // CMD_H
