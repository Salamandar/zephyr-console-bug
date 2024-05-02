#include <zephyr/kernel.h>
#include <zephyr/drivers/led.h>

#define LED_GPIO_NODE_ID DT_COMPAT_GET_ANY_STATUS_OKAY(gpio_leds)
static const struct device *led_gpio = DEVICE_DT_GET(LED_GPIO_NODE_ID);


int main(void) {
	if (!device_is_ready(led_gpio)) {
		printk("Device %s is not ready", led_gpio->name);
		return 0;
	}

	led_on(led_gpio, 0);
	printk("before sleep\n");

	k_msleep(100);
	led_on(led_gpio, 1);
	printk("after 100ms sleep\n");

	k_msleep(1000);
	led_on(led_gpio, 2);
	printk("after sleep\n");

    return 0;
}
