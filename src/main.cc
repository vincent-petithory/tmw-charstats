/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.cc
 * Copyright (C) Vincent Petithory 2010 <vincent.petithory@gmail.com>
 * 
 * tmw-charstats is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * tmw-charstats is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtkmm.h>
#include <iostream>
#include <string>
#include "character.h"


#ifdef ENABLE_NLS
#  include <libintl.h>
#endif


/* For testing propose use the local (not installed) ui file */
#define UI_FILE PACKAGE_DATA_DIR"/tmw_charstats/ui/tmw_charstats.ui"
/* #define UI_FILE "src/tmw_charstats.ui" */

inline void configure_spinbutton(Gtk::SpinButton* spinbutton, const character::character_stat & cs, character* c, unsigned int max_value);
inline void set_status_cost_label(Gtk::Label* label, const character::character_stat & cs, character* c);
void on_value_changed(Gtk::SpinButton* spinbutton, const character::character_stat & cs, character* c);
void update_ui(character* c);

struct ui
{

    // Spin buttons
    Gtk::SpinButton* spinbutton_level;
    Gtk::SpinButton* spinbutton_strength;
    Gtk::SpinButton* spinbutton_agility;
    Gtk::SpinButton* spinbutton_vitality;
    Gtk::SpinButton* spinbutton_intelligence;
    Gtk::SpinButton* spinbutton_dexterity;
    Gtk::SpinButton* spinbutton_luck;

    // Labels
    Gtk::Label* label_strength_cost;
    Gtk::Label* label_agility_cost;
    Gtk::Label* label_vitality_cost;
    Gtk::Label* label_intelligence_cost;
    Gtk::Label* label_dexterity_cost;
    Gtk::Label* label_luck_cost;

    Gtk::Label* label_status_points;
    Gtk::Label* label_total_status_points;
    
};

ui ui_object;

int main (int argc, char *argv[])
{
    Gtk::Main kit(argc, argv);
    
    // Load the Glade file 
    Glib::RefPtr<Gtk::Builder> builder;
    try
    {
        builder = Gtk::Builder::create_from_file(UI_FILE);
    }
    catch (const Glib::FileError & ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    Gtk::Window* main_window = 0;
    builder->get_widget("main_window", main_window);

    // Create the char infos
    character* c = NULL;
    c = new character();

    builder->get_widget("label_strength_cost",ui_object.label_strength_cost);
    builder->get_widget("label_agility_cost",ui_object.label_agility_cost);
    builder->get_widget("label_vitality_cost",ui_object.label_vitality_cost);
    builder->get_widget("label_intelligence_cost",ui_object.label_intelligence_cost);
    builder->get_widget("label_dexterity_cost",ui_object.label_dexterity_cost);
    builder->get_widget("label_luck_cost",ui_object.label_luck_cost);
    builder->get_widget("label_status_points",ui_object.label_status_points);
    builder->get_widget("label_total_status_points",ui_object.label_total_status_points);
    
    // Configure the spin buttons
    // Level
    builder->get_widget("spinbutton_level",ui_object.spinbutton_level);
    configure_spinbutton(ui_object.spinbutton_level, character::LEVEL, c, 255);

    // Strength
    builder->get_widget("spinbutton_strength",ui_object.spinbutton_strength);
    configure_spinbutton(ui_object.spinbutton_strength, character::STRENGTH, c, 255);

    // Agility
    builder->get_widget("spinbutton_agility",ui_object.spinbutton_agility);
    configure_spinbutton(ui_object.spinbutton_agility, character::AGILITY, c, 255);

    // Vitality
    builder->get_widget("spinbutton_vitality",ui_object.spinbutton_vitality);
    configure_spinbutton(ui_object.spinbutton_vitality, character::VITALITY, c, 255);

    // Intelligence
    builder->get_widget("spinbutton_intelligence",ui_object.spinbutton_intelligence);
    configure_spinbutton(ui_object.spinbutton_intelligence, character::INTELLIGENCE, c, 255);

    // Dexterity
    builder->get_widget("spinbutton_dexterity",ui_object.spinbutton_dexterity);
    configure_spinbutton(ui_object.spinbutton_dexterity, character::DEXTERITY, c, 255);

    // Luck
    builder->get_widget("spinbutton_luck",ui_object.spinbutton_luck);
    configure_spinbutton(ui_object.spinbutton_luck, character::LUCK, c, 255);

    update_ui(c);
    
    if (main_window)
    {
        kit.run(*main_window);
    }
    return 0;
}

void on_value_changed(Gtk::SpinButton* spinbutton, const character::character_stat & cs, character* c)
{
    // retrieve the input value
    c->set_stat(cs, spinbutton->get_value_as_int());
    update_ui(c);
}

void update_ui(character* c)
{
    // get status points and stats and assign to inputs
    ui_object.spinbutton_level->set_value(c->get_stat(character::LEVEL));
    ui_object.spinbutton_strength->set_value(c->get_stat(character::STRENGTH));
    ui_object.spinbutton_agility->set_value(c->get_stat(character::AGILITY));
    ui_object.spinbutton_vitality->set_value(c->get_stat(character::VITALITY));
    ui_object.spinbutton_intelligence->set_value(c->get_stat(character::INTELLIGENCE));
    ui_object.spinbutton_dexterity->set_value(c->get_stat(character::DEXTERITY));
    ui_object.spinbutton_luck->set_value(c->get_stat(character::LUCK));

    set_status_cost_label(ui_object.label_strength_cost, character::STRENGTH,c);
    set_status_cost_label(ui_object.label_agility_cost, character::AGILITY,c);
    set_status_cost_label(ui_object.label_vitality_cost, character::VITALITY,c);
    set_status_cost_label(ui_object.label_intelligence_cost, character::INTELLIGENCE,c);
    set_status_cost_label(ui_object.label_dexterity_cost, character::DEXTERITY,c);
    set_status_cost_label(ui_object.label_luck_cost, character::LUCK,c);
    
    char c_total_points[100];
    sprintf(c_total_points, "%d status points available", c->get_total_status_points());
    std::string total_points(c_total_points);
    ui_object.label_total_status_points->set_label(total_points);

    char c_points[100];
    sprintf(c_points, "%d status points remaining", c->get_status_points());
    std::string points(c_points);
    ui_object.label_status_points->set_label(points);
}

inline void set_status_cost_label(Gtk::Label* label, const character::character_stat & cs, character* c)
{
    char c_strength_cost[100];
    sprintf(c_strength_cost, "%d", 
        character::get_required_status_points_for_next_value(
            c->get_stat(cs)
        )
    );
    std::string strength_cost(c_strength_cost);
    label->set_label(strength_cost);
}

inline void configure_spinbutton(Gtk::SpinButton* spinbutton, const character::character_stat & cs, character* c, unsigned int max_value)
{
    spinbutton->set_increments(1, 10);
    spinbutton->set_range(1, max_value);
    spinbutton->set_value(c->get_stat(cs));
    spinbutton->signal_value_changed().connect(
        sigc::bind(
            sigc::ptr_fun(&on_value_changed), spinbutton, cs, c
        )
    );
}

