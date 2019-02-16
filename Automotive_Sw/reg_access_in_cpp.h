#include <iostream>

using namespace std;

typedef unsigned int uint8_t;
typedef unsigned long uint32_t;
typedef volatile unsigned int VUINT8;
typedef volatile unsigned long VUINT32;

static const unsigned int baseAddress = 0xfffe0000;

// New enums for each register width
enum Registers8
{
    STATUS = 0x00 // UART status register
};

enum Registers32
{
    TXBUF = 0x04  // Transmit buffer
};
// Two overloads of regAddress
inline VUINT8 *regAddress(Registers8 reg)
{
    return reinterpret_cast<VUINT8 *>(baseAddress + reg);
}
inline VUINT32 *regAddress(Registers32 reg)
{
    return reinterpret_cast<VUINT32 *>(baseAddress + reg);
}
// Two overloads of regRead
inline uint8_t regRead(Registers8 reg)
{
    return *regAddress(reg);
} 
inline uint32_t regRead(Registers32 reg)
{
    return *regAddress(reg);
}

// Two overloads of regWrite
inline void regWrite(Registers8 reg, uint8_t value)
{
    *regAddress(reg) = value;
}

inline void regWrite(Registers32 reg, uint8_t value)
{
    *regAddress(reg) = value;
}


// A macro that defines enumeration values for a bitset
// You supply the start and end bit positions
#define REG_BIT_DEFN(start, end) ((start<<16)|(end-start+1))
enum STATUS_bits
{
    TX_BUFFER_EMPTY = REG_BIT_DEFN(0, 0),
    RX_BUFFER_EMPTY = REG_BIT_DEFN(1, 1), 
    TX_UNDERRUN     = REG_BIT_DEFN(2, 2), 
    RX_OVERFLOW     = REG_BIT_DEFN(3, 3)
};

inline uint32_t bitRead(Registers32 reg, uint32_t bits)
{
    uint32_t       regval = *regAddress(reg);
    const uint32_t width  = bits & 0xff;
    const uint32_t bitno  = bits >> 16;
    regval >>= bitno;
    regval  &= ((1<<width)-1);
    return regval;
}
inline void bitWrite(Registers32 reg, uint32_t bits, uint32_t value)
{
    uint32_t           regval = *regAddress(reg);
    const uint32_t     width  = bits & 0xff;
    const uint32_t     bitno  = bits >> 16;
    regval &= ~(((1<<width)-1) << bitno);
    regval |=  value << bitno;
    *regAddress(reg) = regval;
}

int main()
{
    return 0;
}
