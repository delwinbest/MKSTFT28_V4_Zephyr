/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "led0" alias. */
#define BUZZER0_NODE DT_ALIAS(buzzer0)

#if DT_NODE_HAS_STATUS(BUZZER0_NODE, okay)
#define BUZZER0	DT_GPIO_LABEL(BUZZER0_NODE, gpios)
#define PIN	DT_GPIO_PIN(BUZZER0_NODE, gpios)
#define FLAGS	DT_GPIO_FLAGS(BUZZER0_NODE, gpios)
#else
/* A build error here means your board isn't set up to blink an LED. */
#error "Unsupported board: buzzer0 devicetree alias is not defined"
#define BUZZER0	""
#define PIN	0
#define FLAGS	0
#endif

void main(void)
{
	const struct device *buzzer;
	bool buzzer_is_on = false;
	int ret;

	buzzer = device_get_binding(BUZZER0);
	if (buzzer == NULL) {
		return;
	}

	ret = gpio_pin_configure(buzzer, PIN, GPIO_OUTPUT_ACTIVE | FLAGS);
	if (ret < 0) {
		return;
	}

	while (1) {
		gpio_pin_set(buzzer, PIN, (int)buzzer_is_on);
		buzzer_is_on = !buzzer_is_on;
		k_msleep(SLEEP_TIME_MS);
	}
}
