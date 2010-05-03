
/* #line 1 "./ragel/tsip_parser_header_Require.rl" */
/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou(at)doubango.org>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsip_header_Require.c
 * @brief SIP Require header.
 *
 * @author Mamadou Diop <diopmamadou(at)doubango.org>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#include "tinySIP/headers/tsip_header_Require.h"

#include "tinySIP/parsers/tsip_parser_uri.h"

#include "tsk_debug.h"
#include "tsk_memory.h"

#include <string.h>



/***********************************
*	Ragel state machine.
*/

/* #line 66 "./ragel/tsip_parser_header_Require.rl" */


tsip_header_Require_t* tsip_header_Require_create(const char* option)
{
	return tsk_object_new(TSIP_HEADER_REQUIRE_VA_ARGS(option));
}

tsip_header_Require_t* tsip_header_Require_create_null()
{
	return tsip_header_Require_create(tsk_null);
}

int tsip_header_Require_tostring(const tsip_header_t* header, tsk_buffer_t* output)
{
	if(header){
		const tsip_header_Require_t *Require = (const tsip_header_Require_t *)header;
		tsk_list_item_t *item;
		tsk_string_t *str;
		int ret = 0;

		tsk_list_foreach(item, Require->options){
			str = item->data;
			if(item == Require->options->head){
				ret = tsk_buffer_append(output, str->value, tsk_strlen(str->value));
			}
			else{
				ret = tsk_buffer_append_2(output, ",%s", str->value);
			}
		}

		return ret;
	}

	return -1;
}

tsip_header_Require_t *tsip_header_Require_parse(const char *data, size_t size)
{
	int cs = 0;
	const char *p = data;
	const char *pe = p + size;
	const char *eof = pe;
	tsip_header_Require_t *hdr_require = tsip_header_Require_create_null();
	
	const char *tag_start;

	
/* #line 96 "./src/headers/tsip_header_Require.c" */
static const char _tsip_machine_parser_header_Require_actions[] = {
	0, 1, 0, 1, 1, 1, 2
};

static const char _tsip_machine_parser_header_Require_key_offsets[] = {
	0, 0, 2, 4, 6, 8, 10, 12, 
	14, 17, 34, 35, 37, 53, 69, 73, 
	74, 76, 79, 80
};

static const char _tsip_machine_parser_header_Require_trans_keys[] = {
	82, 114, 69, 101, 81, 113, 85, 117, 
	73, 105, 82, 114, 69, 101, 9, 32, 
	58, 9, 13, 32, 33, 37, 39, 126, 
	42, 43, 45, 46, 48, 57, 65, 90, 
	95, 122, 10, 9, 32, 9, 32, 33, 
	37, 39, 126, 42, 43, 45, 46, 48, 
	57, 65, 90, 95, 122, 9, 13, 32, 
	33, 37, 39, 44, 126, 42, 46, 48, 
	57, 65, 90, 95, 122, 9, 13, 32, 
	44, 10, 9, 32, 9, 32, 44, 10, 
	0
};

static const char _tsip_machine_parser_header_Require_single_lengths[] = {
	0, 2, 2, 2, 2, 2, 2, 2, 
	3, 7, 1, 2, 6, 8, 4, 1, 
	2, 3, 1, 0
};

static const char _tsip_machine_parser_header_Require_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 5, 0, 0, 5, 4, 0, 0, 
	0, 0, 0, 0
};

static const char _tsip_machine_parser_header_Require_index_offsets[] = {
	0, 0, 3, 6, 9, 12, 15, 18, 
	21, 25, 38, 40, 43, 55, 68, 73, 
	75, 78, 82, 84
};

static const char _tsip_machine_parser_header_Require_indicies[] = {
	0, 0, 1, 2, 2, 1, 3, 3, 
	1, 4, 4, 1, 5, 5, 1, 6, 
	6, 1, 7, 7, 1, 7, 7, 8, 
	1, 8, 9, 8, 10, 10, 10, 10, 
	10, 10, 10, 10, 10, 1, 11, 1, 
	12, 12, 1, 12, 12, 10, 10, 10, 
	10, 10, 10, 10, 10, 10, 1, 13, 
	14, 13, 15, 15, 15, 16, 15, 15, 
	15, 15, 15, 1, 17, 18, 17, 8, 
	1, 19, 1, 20, 20, 1, 20, 20, 
	8, 1, 21, 1, 1, 0
};

static const char _tsip_machine_parser_header_Require_trans_targs[] = {
	2, 0, 3, 4, 5, 6, 7, 8, 
	9, 10, 13, 11, 12, 14, 18, 13, 
	9, 14, 15, 16, 17, 19
};

static const char _tsip_machine_parser_header_Require_trans_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 1, 0, 0, 3, 3, 0, 
	3, 0, 0, 0, 0, 5
};

static const int tsip_machine_parser_header_Require_start = 1;
static const int tsip_machine_parser_header_Require_first_final = 19;
static const int tsip_machine_parser_header_Require_error = 0;

static const int tsip_machine_parser_header_Require_en_main = 1;


/* #line 113 "./ragel/tsip_parser_header_Require.rl" */
	
/* #line 174 "./src/headers/tsip_header_Require.c" */
	{
	cs = tsip_machine_parser_header_Require_start;
	}

/* #line 114 "./ragel/tsip_parser_header_Require.rl" */
	
/* #line 181 "./src/headers/tsip_header_Require.c" */
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _tsip_machine_parser_header_Require_trans_keys + _tsip_machine_parser_header_Require_key_offsets[cs];
	_trans = _tsip_machine_parser_header_Require_index_offsets[cs];

	_klen = _tsip_machine_parser_header_Require_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _tsip_machine_parser_header_Require_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _tsip_machine_parser_header_Require_indicies[_trans];
	cs = _tsip_machine_parser_header_Require_trans_targs[_trans];

	if ( _tsip_machine_parser_header_Require_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _tsip_machine_parser_header_Require_actions + _tsip_machine_parser_header_Require_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
/* #line 50 "./ragel/tsip_parser_header_Require.rl" */
	{
		tag_start = p;
	}
	break;
	case 1:
/* #line 54 "./ragel/tsip_parser_header_Require.rl" */
	{
		TSK_PARSER_ADD_STRING(hdr_require->options);
	}
	break;
	case 2:
/* #line 58 "./ragel/tsip_parser_header_Require.rl" */
	{
	}
	break;
/* #line 272 "./src/headers/tsip_header_Require.c" */
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

/* #line 115 "./ragel/tsip_parser_header_Require.rl" */
	
	if( cs < 
/* #line 288 "./src/headers/tsip_header_Require.c" */
19
/* #line 116 "./ragel/tsip_parser_header_Require.rl" */
 ){
		TSK_DEBUG_ERROR("Failed to parse 'Require' header.");
		TSK_OBJECT_SAFE_FREE(hdr_require);
	}
	
	return hdr_require;
}







//========================================================
//	Require header object definition
//

static tsk_object_t* tsip_header_Require_ctor(tsk_object_t *self, va_list * app)
{
	tsip_header_Require_t *Require = self;
	if(Require){
		const char* option;

		TSIP_HEADER(Require)->type = tsip_htype_Require;
		TSIP_HEADER(Require)->tostring = tsip_header_Require_tostring;

		if((option = va_arg(*app, const char*))){
			tsk_string_t* string = tsk_string_create(option);
			Require->options = tsk_list_create();

			tsk_list_push_back_data(Require->options, ((void**) &string));
		}
	}
	else{
		TSK_DEBUG_ERROR("Failed to create new Require header.");
	}
	return self;
}

static tsk_object_t* tsip_header_Require_dtor(tsk_object_t *self)
{
	tsip_header_Require_t *Require = self;
	if(Require){
		TSK_OBJECT_SAFE_FREE(Require->options);
	}
	else{
		TSK_DEBUG_ERROR("Null Require header.");
	}

	return self;
}

static const tsk_object_def_t tsip_header_Require_def_s = 
{
	sizeof(tsip_header_Require_t),
	tsip_header_Require_ctor,
	tsip_header_Require_dtor,
	tsk_null
};
const tsk_object_def_t *tsip_header_Require_def_t = &tsip_header_Require_def_s;