


#ifndef BIT_MATHS_H_
#define BIT_MATHS_H_


#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)
#define TOGGLE_BIT(REG,BIT) REG^=(1<<BIT)
#define READ_BIT(REG,BIT)   ((REG>>BIT)&1)
#define WRITE_BIT(REG,BIT,VALUE) REG=(VALUE<<BIT) | (REG&=~(1<<BIT))


#endif
