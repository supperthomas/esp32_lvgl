/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"

static lv_obj_t * screen_datetext_1_calendar;
void screen_datetext_1_calendar_event_handler(lv_event_t * e);
void screen_datetext_1_init_calendar(lv_obj_t *parent);;
void screen_datetext_1_event(lv_event_t*e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * btn = lv_event_get_target(e);
	if(code == LV_EVENT_FOCUSED){
		if(screen_datetext_1_calendar == NULL){
			screen_datetext_1_init_calendar(guider_ui.screen);
		}
	}
}
void screen_datetext_1_init_calendar(lv_obj_t *parent)
{
	if (screen_datetext_1_calendar == NULL){
		lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
		screen_datetext_1_calendar = lv_calendar_create(lv_layer_top());
 
		lv_obj_set_size(screen_datetext_1_calendar,240,240);
		lv_calendar_set_showed_date(screen_datetext_1_calendar,2022,05);
		lv_obj_align(screen_datetext_1_calendar,LV_ALIGN_CENTER,20,20);
 
		lv_obj_add_event_cb(screen_datetext_1_calendar,screen_datetext_1_calendar_event_handler,LV_EVENT_ALL,NULL);
		lv_calendar_header_arrow_create(screen_datetext_1_calendar);
		lv_obj_update_layout(parent);
	}
}
void screen_datetext_1_calendar_event_handler(lv_event_t * e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * obj = lv_event_get_current_target(e);
 
	if (code == LV_EVENT_VALUE_CHANGED){
		lv_calendar_date_t date;
		lv_calendar_get_pressed_date(obj,&date);
		char buf[16];
		lv_snprintf(buf,sizeof(buf),"%d/%02d/%02d", date.year, date.month ,date.day);
		lv_label_set_text(guider_ui.screen_datetext_1, buf);
		lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
		lv_obj_set_style_bg_opa(lv_layer_top(), LV_OPA_TRANSP, 0);
		lv_obj_del(screen_datetext_1_calendar);
		screen_datetext_1_calendar = NULL;
	}
}
static const lv_img_dsc_t* screen_animimg_1_imgs[1] = {
	&screen_animimg_1picture
};

void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_main_main_default
	static lv_style_t style_screen_main_main_default;
	if (style_screen_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_main_main_default);
	else
		lv_style_init(&style_screen_main_main_default);
	lv_style_set_bg_color(&style_screen_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_screen_main_main_default, 0);
	lv_obj_add_style(ui->screen, &style_screen_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img2
	ui->screen_img2 = lv_img_create(ui->screen);
	lv_obj_set_pos(ui->screen_img2, 0, 0);
	lv_obj_set_size(ui->screen_img2, 240, 240);
	lv_obj_set_scrollbar_mode(ui->screen_img2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img2_main_main_default
	static lv_style_t style_screen_img2_main_main_default;
	if (style_screen_img2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img2_main_main_default);
	else
		lv_style_init(&style_screen_img2_main_main_default);
	lv_style_set_img_recolor(&style_screen_img2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img2_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img2_main_main_default, 64);
	lv_obj_add_style(ui->screen_img2, &style_screen_img2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img2,&_scan_example_240x240);
	lv_img_set_pivot(ui->screen_img2, 0,0);
	lv_img_set_angle(ui->screen_img2, 0);

	//Write datetext screen_datetext_1
	ui->screen_datetext_1 = lv_label_create(ui->screen);
	lv_label_set_text(ui->screen_datetext_1, "2022/12/16");
	lv_obj_set_style_text_align(ui->screen_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
	lv_obj_set_pos(ui->screen_datetext_1, 3, 206);
	lv_obj_set_size(ui->screen_datetext_1, 113, 27);

	//write datetext event
	lv_obj_add_flag(ui->screen_datetext_1, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_add_event_cb(ui->screen_datetext_1, screen_datetext_1_event, LV_EVENT_ALL, NULL);

	//Write style state: LV_STATE_DEFAULT for style_screen_datetext_1_main_main_default
	static lv_style_t style_screen_datetext_1_main_main_default;
	if (style_screen_datetext_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_datetext_1_main_main_default);
	else
		lv_style_init(&style_screen_datetext_1_main_main_default);
	lv_style_set_radius(&style_screen_datetext_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_datetext_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_datetext_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_datetext_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_datetext_1_main_main_default, 255);
	lv_style_set_text_color(&style_screen_datetext_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_datetext_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_screen_datetext_1_main_main_default, 2);
	lv_style_set_pad_left(&style_screen_datetext_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_datetext_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_datetext_1_main_main_default, 7);
	lv_obj_add_style(ui->screen_datetext_1, &style_screen_datetext_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_spangroup_1
	ui->screen_spangroup_1 = lv_spangroup_create(ui->screen);
	lv_obj_set_pos(ui->screen_spangroup_1, 14, 57);
	lv_obj_set_size(ui->screen_spangroup_1, 49, 28);
	lv_obj_set_scrollbar_mode(ui->screen_spangroup_1, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->screen_spangroup_1, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_1, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_screen_spangroup_1_main_main_default
	static lv_style_t style_screen_spangroup_1_main_main_default;
	if (style_screen_spangroup_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_spangroup_1_main_main_default);
	else
		lv_style_init(&style_screen_spangroup_1_main_main_default);
	lv_style_set_radius(&style_screen_spangroup_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_spangroup_1_main_main_default, lv_color_make(0x35, 0xe8, 0x11));
	lv_style_set_bg_grad_color(&style_screen_spangroup_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_spangroup_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_spangroup_1_main_main_default, 200);
	lv_style_set_border_color(&style_screen_spangroup_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_screen_spangroup_1_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_spangroup_1_main_main_default, 255);
	lv_style_set_pad_left(&style_screen_spangroup_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_1, &style_screen_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//create spans
	lv_span_t *screen_spangroup_1_span;
extern int dh11_temperature;
extern int dh11_humidity;
    char dh11_str[10] ={0};
	sprintf(dh11_str,"%d*C",dh11_temperature);
	printf("dh——Temperature:%d*C ", dh11_temperature);
	printf("dh——Humidity:%d%%\n", dh11_humidity);
	//create a new span
	screen_spangroup_1_span = lv_spangroup_new_span(ui->screen_spangroup_1);
	lv_span_set_text(screen_spangroup_1_span, dh11_str);
	lv_style_set_text_color(&screen_spangroup_1_span->style, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_decor(&screen_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_1_span->style, &lv_font_simsun_24);
	lv_spangroup_refr_mode(ui->screen_spangroup_1);

	//Write codes screen_label_1
	ui->screen_label_1 = lv_label_create(ui->screen);
	lv_obj_set_pos(ui->screen_label_1, 14, 85);
	lv_obj_set_size(ui->screen_label_1, 100, 32);
	lv_obj_set_scrollbar_mode(ui->screen_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_1, "当前湿度值");
	lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_1_main_main_default
	static lv_style_t style_screen_label_1_main_main_default;
	if (style_screen_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_1_main_main_default);
	else
		lv_style_init(&style_screen_label_1_main_main_default);
	lv_style_set_radius(&style_screen_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_label_1_main_main_default, 255);
	lv_style_set_text_color(&style_screen_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_label_1_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_screen_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_screen_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_screen_label_1_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_1, &style_screen_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_label_2
	ui->screen_label_2 = lv_label_create(ui->screen);
	lv_obj_set_pos(ui->screen_label_2, 14, 11);
	lv_obj_set_size(ui->screen_label_2, 100, 32);
	lv_obj_set_scrollbar_mode(ui->screen_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->screen_label_2, "当前温度值");
	lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_screen_label_2_main_main_default
	static lv_style_t style_screen_label_2_main_main_default;
	if (style_screen_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_label_2_main_main_default);
	else
		lv_style_init(&style_screen_label_2_main_main_default);
	lv_style_set_radius(&style_screen_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_label_2_main_main_default, 255);
	lv_style_set_text_color(&style_screen_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen_label_2_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_letter_space(&style_screen_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_screen_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_screen_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_screen_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_screen_label_2_main_main_default, 0);
	lv_obj_add_style(ui->screen_label_2, &style_screen_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_spangroup_2
	ui->screen_spangroup_2 = lv_spangroup_create(ui->screen);
	lv_obj_set_pos(ui->screen_spangroup_2, 14, 129);
	lv_obj_set_size(ui->screen_spangroup_2, 90, 33);
	lv_obj_set_scrollbar_mode(ui->screen_spangroup_2, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->screen_spangroup_2, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->screen_spangroup_2, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->screen_spangroup_2, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_screen_spangroup_2_main_main_default
	static lv_style_t style_screen_spangroup_2_main_main_default;
	if (style_screen_spangroup_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_spangroup_2_main_main_default);
	else
		lv_style_init(&style_screen_spangroup_2_main_main_default);
	lv_style_set_radius(&style_screen_spangroup_2_main_main_default, 0);
	lv_style_set_bg_color(&style_screen_spangroup_2_main_main_default, lv_color_make(0xff, 0x1e, 0x05));
	lv_style_set_bg_grad_color(&style_screen_spangroup_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen_spangroup_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_spangroup_2_main_main_default, 255);
	lv_style_set_border_color(&style_screen_spangroup_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_screen_spangroup_2_main_main_default, 0);
	lv_style_set_border_opa(&style_screen_spangroup_2_main_main_default, 255);
	lv_style_set_pad_left(&style_screen_spangroup_2_main_main_default, 0);
	lv_style_set_pad_right(&style_screen_spangroup_2_main_main_default, 0);
	lv_style_set_pad_top(&style_screen_spangroup_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen_spangroup_2_main_main_default, 0);
	lv_obj_add_style(ui->screen_spangroup_2, &style_screen_spangroup_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//create spans
	lv_span_t *screen_spangroup_2_span;
	sprintf(dh11_str,"%d%%",dh11_humidity);	
	//create a new span
	screen_spangroup_2_span = lv_spangroup_new_span(ui->screen_spangroup_2);
	lv_span_set_text(screen_spangroup_2_span, dh11_str);
	lv_style_set_text_color(&screen_spangroup_2_span->style, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_decor(&screen_spangroup_2_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&screen_spangroup_2_span->style, &lv_font_simsun_24);
	lv_spangroup_refr_mode(ui->screen_spangroup_2);

	//Write codes screen_animimg_1
	ui->screen_animimg_1 = lv_animimg_create(ui->screen);
	lv_obj_set_pos(ui->screen_animimg_1, 129, 11);
	lv_obj_set_size(ui->screen_animimg_1, 100, 100);
	lv_obj_set_scrollbar_mode(ui->screen_animimg_1, LV_SCROLLBAR_MODE_OFF);
	lv_animimg_set_src(ui->screen_animimg_1, (const void **) screen_animimg_1_imgs, 1);
	lv_animimg_set_duration(ui->screen_animimg_1, 30);
	lv_animimg_set_repeat_count(ui->screen_animimg_1, 3000);
	lv_animimg_start(ui->screen_animimg_1);

	//Write codes screen_img_1
	ui->screen_img_1 = lv_img_create(ui->screen);
	lv_obj_set_pos(ui->screen_img_1, 129, 129);
	lv_obj_set_size(ui->screen_img_1, 100, 100);
	lv_obj_set_scrollbar_mode(ui->screen_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_screen_img_1_main_main_default
	static lv_style_t style_screen_img_1_main_main_default;
	if (style_screen_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_screen_img_1_main_main_default);
	else
		lv_style_init(&style_screen_img_1_main_main_default);
	lv_style_set_img_recolor(&style_screen_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_screen_img_1_main_main_default, 255);
	lv_obj_add_style(ui->screen_img_1, &style_screen_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_1,&_laq_100x100);
	lv_img_set_pivot(ui->screen_img_1, 50,50);
	lv_img_set_angle(ui->screen_img_1, 0);
}