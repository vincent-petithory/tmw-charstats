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

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class character
{
public:

	enum character_stat {STRENGTH,AGILITY,VITALITY,INTELLIGENCE,DEXTERITY,LUCK,LEVEL};

	character();
	~character();
	
	int get_status_points();
	int get_total_status_points();
	
	int get_stat(const character_stat & s);
	void set_stat(const character_stat & s, int value);

	static int get_required_status_points_for_next_value(const int actual_value);
	static int get_required_status_points_for_value(const int value);
	
private:

	int strength;
	int agility;
	int vitality;
	int intelligence;
	int dexterity;
	int luck;

	int level;

};

#endif // _CHARACTER_H_
