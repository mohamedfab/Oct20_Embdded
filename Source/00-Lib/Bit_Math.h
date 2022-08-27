#ifndef BIT_MATH_H_INCLUDED
#define BIT_MATH_H_INCLUDED


#define SET_BIT(REG,BIT_NO)     (REG|=(1<<BIT_NO))
#define CLEAR_BIT(REG,BIT_NO)   (REG&=~(1<<BIT_NO))
#define FLIP_BIT(REG,BIT_NO)    (REG^=(1<<BIT_NO))
#define CHECK_BIT(REG,BIT_NO)   ((REG>>BIT_NO)&1)


#endif // BIT_MATH_H_INCLUDED
