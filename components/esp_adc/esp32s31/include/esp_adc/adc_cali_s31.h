/*
 * SPDX-FileCopyrightText: 2026 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

// Adapted from Espressif's ESP32-S31 Korvo calibration header:
// https://github.com/espressif/esp-dev-kits/blob/6f4b0f6e/examples/esp32-s31-korvo/examples/common_components/esp32_s31_korvo/priv_include/bsp_adc_calibration.h
// Changes: rename and document the driver API.

#pragma once

#include "esp_err.h"
#include "esp_adc/adc_oneshot.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize software calibration for ESP32-S31 ADC1.
 *
 * The caller must own the oneshot unit and serialize access while calibration
 * reads the configured channel. Weights are shared across ADC1 channels.
 * ADC2 is not supported. Repeated calls restore the calibrated raw-data mode.
 */
esp_err_t adc_cali_s31_init(adc_oneshot_unit_handle_t handle,
                                       adc_unit_t unit,
                                       adc_channel_t channel);

/** Convert one weighted raw ADC1 sample to millivolts after initialization. */
esp_err_t adc_cali_s31_raw_to_voltage(adc_unit_t unit, int raw, int *voltage_mv);

#ifdef __cplusplus
}
#endif
