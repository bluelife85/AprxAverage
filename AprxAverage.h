/**
 * @file AprxAverage.h
 * @author bluelife85 (bluelife85@naver.com)
 * @brief Approximate Average
 * 
 * This module provides a lightweight approximate average filter,
 * designed for smoothing integer-based signals with minimal memory usage.
 * It does not maintain a full history buffer, reducing RAM consumption.
 */
#ifndef __APPROXIMATE_AVERAGE_H__
#define __APPROXIMATE_AVERAGE_H__

#include "stdint.h"
#if !defined(__STDC_VERSION__) || (__STDC_VERSION__ < 202311L)
#include <stdbool.h>
#endif /* __STDC_VERSION__ */

/**
 * @def DEFAULT_AVERAGE_WINDOW_SIZE
 * @brief Default window size for the approximate average filter.
 */
#define DEFAULT_AVERAGE_WINDOW_SIZE (10u)

/**
 * @struct AprxAverage
 * @brief Structure for managing approximate average state.
 *
 * This structure holds the internal state for computing a moving average
 * without storing a history buffer.
 *
 * - `sum`: Accumulated error-adjusted sum used for incremental averaging.
 * - `average`: Current average value.
 * - `window`: Number of samples to average over.
 * - `count`: Number of values processed, capped by `window`.
 */
struct AprxAverage
{
    int32_t sum;
    int32_t average;
    uint16_t window;
    uint16_t count;
};

/**
 * @brief Initializes the approximate average filter.
 *
 * This sets the window size and resets all internal values.
 *
 * @param obj Pointer to the AprxAverage structure.
 * @param window_size Number of samples to consider for averaging.
 */
void AAVG_Initialize(struct AprxAverage* obj, uint16_t window_size);

/**
 * @brief Applies the approximate averaging algorithm with a new data point.
 *
 * Instead of keeping a history buffer, it updates an accumulated sum
 * with the difference between new data and current average,
 * and adjusts the average accordingly.
 *
 * This approach is memory-efficient but may exhibit slower adaptation
 * to sharp input changes compared to true moving average filters.
 *
 * @param obj Pointer to the AprxAverage structure.
 * @param newData New sample to include in the average.
 */
void AAVG_Averaging(struct AprxAverage* obj, int32_t newData);


/**
 * @brief Resets the filter to its initial state.
 *
 * Clears the sum, average, and count fields. Used before starting a new stream.
 *
 * @param obj Pointer to the AprxAverage structure.
 */
static inline void AAVG_Reset(struct AprxAverage* obj)
{
    obj->sum = 0;
    obj->count = 0;
    obj->average = 0;
}
#endif /* __APPROXIMATE_AVERAGE_H__ */
