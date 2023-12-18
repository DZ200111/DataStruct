#ifndef __DYNAMICARRAY_H_
#define __DYNAMICARRAY_H_
//避免头文件重复包含

typedef int ELEMENTTYPE;
struct dynamicArray
{
    ELEMENTTYPE *data;  //数组的空间
    int len;   //数组的大小
    int capacity; //数组的容量
};

//API:application program interface

//动态数组初始化
int dynamicArrayInit();

//动态数组插入数据（默认从数组尾部插入）
int dynamicArrayInsertData();

//动态数组插入数据，在指定位置插入
int dynamicArrayAppointposInsertData();

//动态数组修改指定位置的数据 ?重复
int dynamicArrayModifAppointPosData();

//动态数组删除数据（默认情况删除尾部数据）
int dynamicArrayDeleteData();

//动态数组删除指定位置的数据

int dynamicArrayDeleteAppointPosData();

//动态数组的销毁
int dynamicArrayDestroy();

//获取动态数组的大小
int dynamicArrayGetSize();

//获取动态数组的容量
int dynamicArrayGetCapacity();

typedef struct dynamicArray DyArray;

#endif