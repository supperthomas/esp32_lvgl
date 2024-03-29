/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "lvgl/demos/generated/guider_fonts/guider_fonts.h"

typedef struct
{
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_img2;
	lv_obj_t *screen_datetext_1;
	lv_obj_t *screen_spangroup_1;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_label_2;
	lv_obj_t *screen_spangroup_2;
	lv_obj_t *screen_animimg_1;
	lv_obj_t *screen_img_1;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);

#include "extra/widgets/animimg/lv_animimg.h"
LV_IMG_DECLARE(screen_animimg_1picture)
LV_IMG_DECLARE(_scan_example_240x240);
LV_IMG_DECLARE(_laq_100x100);

#ifdef __cplusplus
}
#endif
#endif