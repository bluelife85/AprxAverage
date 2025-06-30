/**
 * @file AprxAverage.c
 * @author bluelife85 (bluelife85@naver.com)
 * @brief Approximate Average
 */
#include "AprxAverage.h"

void AAVG_Initialize(struct AprxAverage* obj, uint16_t window_size)
{
    if(window_size == 0)
        obj->window = DEFAULT_AVERAGE_WINDOW_SIZE;
    else
        obj->window = window_size;
    AAVG_Reset(obj);
}

void AAVG_Averaging(struct AprxAverage* obj, int32_t newData)
{
    int32_t v;

    v = newData - obj->average;
    if(obj->count == 0)
        obj->sum = v;
    else
        obj->sum += v;
    
    if(++obj->count > obj->window)
    {
        obj->count = obj->window;
        obj->sum -= obj->average;
    }
    v = obj->sum / obj->count;
    obj->average = v;
    return v;
}
