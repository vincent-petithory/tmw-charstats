/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * tmw-charstats
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

#include "character.h"

character::character():
	strength(1), 
	agility(1), 
	vitality(1), 
	intelligence(1), 
	dexterity(1), 
	luck(1), 
	level(1) 
{

}

character::~character() {}

int character::get_status_points()
{
	int status_points = this->get_total_status_points() - (
			character::get_required_status_points_for_value(this->strength) + 
			character::get_required_status_points_for_value(this->agility) + 
			character::get_required_status_points_for_value(this->vitality) + 
			character::get_required_status_points_for_value(this->intelligence) + 
			character::get_required_status_points_for_value(this->dexterity) + 
			character::get_required_status_points_for_value(this->luck)
		);
	return status_points;
}

int character::get_total_status_points()
{
	int status_points = 45;
    int i;
	
    for (i = 1; i <= this->level; i++)
        status_points += (i + 14) / 4;
	return status_points;
}

int character::get_stat(const character_stat & s)
{
	switch (s)
	{
		case STRENGTH:
			return this->strength;
		case AGILITY:
			return this->agility;
		case VITALITY:
			return this->vitality;
		case INTELLIGENCE:
			return this->intelligence;
		case DEXTERITY:
			return this->dexterity;
		case LUCK:
			return this->luck;
		case LEVEL:
			return this->level;
		default: 
			return 0;
	}
}

void character::set_stat(const character_stat & s, int value)
{
	switch (s)
	{
		case STRENGTH:
			this->strength = value;
			break;
		case AGILITY:
			this->agility = value;
			break;
		case VITALITY:
			this->vitality = value;
			break;
		case INTELLIGENCE:
			this->intelligence = value;
			break;
		case DEXTERITY:
			this->dexterity = value;
			break;
		case LUCK:
			this->luck = value;
			break;
		case LEVEL:
			this->level = value;
			break;
		default:
			break;
	}
}

int character::get_required_status_points_for_next_value(const int actual_value)
{
    return 2+(actual_value-1)/10;
}

int character::get_required_status_points_for_value(const int value)
{
	int points = 0;
	int i;
	
    for (i = 1; i < value; i++)
		points += 2+(i-1)/10;
    return points;
}



