/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "stdint.h"
#ifdef VIA_ENABLE
#    include "via.h"
#endif
#include "quantum_keycodes.h"

enum custom_keycodes {
    KC_LOPTN = QK_KB_2, // TECH DEBT: Starts at QK_KB_2 to maintain ordering with VIA definitions. See #19884. Revert to QK_KB_0 when VIA catches up with QMK.
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_SIRI,
    KC_SPOTLIGHT,
    KC_MAC_DND,
    KC_MAC_LOCK,
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_SPTL KC_SPOTLIGHT
#define KC_LPAD KC_LAUNCHPAD
#define KC_MDND KC_MAC_DND

#define HSS(report) host_system_send(record->event.pressed ? report : 0); return false
#define HCS(report) host_consumer_send(record->event.pressed ? report : 0); return false


typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[3];
} key_combination_t;

void housekeeping_task_polutropon(void);
bool process_record_polutropon(uint16_t keycode, keyrecord_t *record);
