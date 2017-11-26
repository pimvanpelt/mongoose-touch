#ifndef __WIDGET_H
#define __WIDGET_H

struct widget_t;

#define EV_WIDGET_NONE       0
#define EV_WIDGET_CREATE     1
#define EV_WIDGET_DESTROY    2
#define EV_WIDGET_DRAW       3
#define EV_WIDGET_REDRAW     4
#define EV_WIDGET_TIMER      5
#define EV_WIDGET_TOUCH_UP   6
#define EV_WIDGET_TOUCH_DOWN 7

typedef void (*widget_event_fn)(int ev, struct widget_t *w, void *ev_data);

struct widget_t {
  uint16_t x, y, w, h;

  uint32_t timer_msec;      // 0 to disable
  widget_event_fn handler;  // Event callback for this widget
  void *user_data;          // User supplied data

  // Private
  mgos_timer_id _timer_id;
};

struct widget_t *widget_add(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint32_t timer_msec, widget_event_fn handler, void *user_data);
struct widget_t *widget_find(uint16_t x, uint16_t y);
void widget_remove(struct widget_t *widget);

void widget_time_ev(int ev, struct widget_t *w, void *ev_data);

void widget_wifi_ev(int ev, struct widget_t *w, void *ev_data);

void widget_network_ev(int ev, struct widget_t *w, void *ev_data);
void widget_network_send();
void widget_network_recv();

void widget_topbar_ev(int ev, struct widget_t *w, void *ev_data);

void widget_name_ev(int ev, struct widget_t *w, void *ev_data);

#endif // __WIDGET_H