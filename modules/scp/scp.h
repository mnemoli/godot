#ifndef SCP_H_
#define SCP_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "thirdparty/kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class scp_t : public kaitai::kstruct {

public:
	class action_t;
	class scripts_t;
	class script_t;

	enum verbs_t {
		VERBS_STARTPOS = 1073741824,
		VERBS_ACTIONDONE0 = 1073741825,
		VERBS_ACTIONSTART1 = 1073741826,
		VERBS_ALIGNSCRIPTS0 = 1073741827,
		VERBS_ALIGNBALLTOPTSETUP3 = 1073741828,
		VERBS_ALIGNBALLTOPTGO0 = 1073741829,
		VERBS_ALIGNBALLTOPTSTOP0 = 1073741830,
		VERBS_ALIGNFUDGEBALLTOPTSETUP2 = 1073741831,
		VERBS_BLENDTOFRAME3 = 1073741832,
		VERBS_CUECODE1 = 1073741833,
		VERBS_DEBUGCODE1 = 1073741834,
		VERBS_DISABLEFUDGEAIM1 = 1073741835,
		VERBS_DISABLESWING0 = 1073741836,
		VERBS_DONETALKING0 = 1073741837,
		VERBS_DONETALKING1 = 1073741838,
		VERBS_ENABLEFUDGEAIM1 = 1073741839,
		VERBS_ENABLESWING1 = 1073741840,
		VERBS_ENDBLOCK0 = 1073741841,
		VERBS_ENDBLOCKALIGN0 = 1073741842,
		VERBS_GLUESCRIPTS0 = 1073741843,
		VERBS_GLUESCRIPTSBALL1 = 1073741844,
		VERBS_INTERRUPTIONSDISABLE0 = 1073741845,
		VERBS_INTERRUPTIONSENABLE0 = 1073741846,
		VERBS_LOOKATLOCATION2 = 1073741847,
		VERBS_LOOKATLOCATIONEYES2 = 1073741848,
		VERBS_LOOKATRANDOMPT0 = 1073741849,
		VERBS_LOOKATRANDOMPTEYES0 = 1073741850,
		VERBS_LOOKATSPRITE1 = 1073741851,
		VERBS_LOOKATSPRITEEYES1 = 1073741852,
		VERBS_LOOKATUSER0 = 1073741853,
		VERBS_LOOKFORWARD0 = 1073741854,
		VERBS_LOOKFORWARDEYES0 = 1073741855,
		VERBS_NULL0 = 1073741856,
		VERBS_NULL1 = 1073741857,
		VERBS_NULL2 = 1073741858,
		VERBS_NULL3 = 1073741859,
		VERBS_NULL4 = 1073741860,
		VERBS_NULL5 = 1073741861,
		VERBS_NULL6 = 1073741862,
		VERBS_PLAYACTION2 = 1073741863,
		VERBS_PLAYACTIONRECALL2 = 1073741864,
		VERBS_PLAYACTIONSTORE2 = 1073741865,
		VERBS_PLAYLAYEREDACTION3 = 1073741866,
		VERBS_PLAYLAYEREDACTION4 = 1073741867,
		VERBS_PLAYLAYEREDACTIONCALLBACK5 = 1073741868,
		VERBS_PLAYLAYEREDACTIONCALLBACK6 = 1073741869,
		VERBS_PLAYTRANSITIONTOACTION1 = 1073741870,
		VERBS_RAND2 = 1073741871,
		VERBS_RESETFUDGER1 = 1073741872,
		VERBS_RESUMEFUDGING1 = 1073741873,
		VERBS_RESUMELAYERROTATION1 = 1073741874,
		VERBS_SEQUENCE2 = 1073741875,
		VERBS_SEQUENCETOEND1 = 1073741876,
		VERBS_SEQUENCETOSTART1 = 1073741877,
		VERBS_SETBLENDOFFSET3 = 1073741878,
		VERBS_SETFUDGEAIMDEFAULTS5 = 1073741879,
		VERBS_SETFUDGERDRIFT2 = 1073741880,
		VERBS_SETFUDGERRATE2 = 1073741881,
		VERBS_SETFUDGERTARGET2 = 1073741882,
		VERBS_SETFUDGERNOW2 = 1073741883,
		VERBS_SETHEADTRACKACUTENESS = 1073741884,
		VERBS_SETHEADTRACKMODE1 = 1073741885,
		VERBS_SETLAYEREDBASEFRAME2 = 1073741886,
		VERBS_SETMOTIONSCALE1 = 1073741887,
		VERBS_SETMOTIONSCALE2 = 1073741888,
		VERBS_SETREVERSEHEADTRACK1 = 1073741889,
		VERBS_SETROTATIONPIVOTBALL1 = 1073741890,
		VERBS_SOUNDEMPTYQUEUE0 = 1073741891,
		VERBS_SOUNDLOOP1 = 1073741892,
		VERBS_SOUNDSETPAN1 = 1073741893,
		VERBS_SOUNDPLAY1 = 1073741894,
		VERBS_SOUNDPLAY2 = 1073741895,
		VERBS_SOUNDPLAY3 = 1073741896,
		VERBS_SOUNDPLAY4 = 1073741897,
		VERBS_SOUNDPLAY5 = 1073741898,
		VERBS_SOUNDQUEUE1 = 1073741899,
		VERBS_SOUNDQUEUE2 = 1073741900,
		VERBS_SOUNDQUEUE3 = 1073741901,
		VERBS_SOUNDQUEUE4 = 1073741902,
		VERBS_SOUNDQUEUE5 = 1073741903,
		VERBS_SOUNDSETDEFLTVOCPITCH1 = 1073741904,
		VERBS_SOUNDSETPITCH1 = 1073741905,
		VERBS_SOUNDSETVOLUME1 = 1073741906,
		VERBS_SOUNDSTOP0 = 1073741907,
		VERBS_STARTLISTENING0 = 1073741908,
		VERBS_STARTBLOCKLOOP1 = 1073741909,
		VERBS_STARTBLOCKCALLBACK2 = 1073741910,
		VERBS_STARTBLOCKCHANCE1 = 1073741911,
		VERBS_STARTBLOCKDIALOGSYNCH0 = 1073741912,
		VERBS_STARTBLOCKELSE0 = 1073741913,
		VERBS_STARTBLOCKLISTEN0 = 1073741914,
		VERBS_STOPFUDGING1 = 1073741915,
		VERBS_SUSPENDFUDGING1 = 1073741916,
		VERBS_SUSPENDLAYERROTATION1 = 1073741917,
		VERBS_TAILSETNEUTRAL1 = 1073741918,
		VERBS_TAILSETRESTORENEUTRAL1 = 1073741919,
		VERBS_TAILSETWAG1 = 1073741920,
		VERBS_TARGETSPRITE4 = 1073741921,
		VERBS_THROWME0 = 1073741922,
		VERBS_ENDPOS = 1073741923
	};

	enum cuecodes_t {
		CUECODES_INTRODONE = 0,
		CUECODES_INTRONOTDONE = 1,
		CUECODES_GRABOBJECT = 2,
		CUECODES_RELEASEOBJECT = 3,
		CUECODES_LOOKATINTEREST = 4,
		CUECODES_LOOKATINTERACTOR = 5,
		CUECODES_USEOBJECT = 6,
		CUECODES_SWATOBJECT = 7,
		CUECODES_GNAWOBJECT = 8,
		CUECODES_SCRATCHOBJECT = 9,
		CUECODES_DIGHOLE = 10,
		CUECODES_FILLHOLE = 11,
		CUECODES_TRIP = 12,
		CUECODES_SNOREACTIVE = 13,
		CUECODES_SNOREIN = 14,
		CUECODES_SNOREOUT = 15,
		CUECODES_SNOREDREAM = 16,
		CUECODES_ATEFOOD = 17,
		CUECODES_SCARE = 18,
		CUECODES_STEPHANDL = 19,
		CUECODES_STEPHANDR = 20,
		CUECODES_STEPFOOTL = 21,
		CUECODES_STEPFOOTR = 22,
		CUECODES_STOMPHANDL = 23,
		CUECODES_STOMPHANDR = 24,
		CUECODES_STOMPFOOTL = 25,
		CUECODES_STOMPFOOTR = 26,
		CUECODES_LAND = 27,
		CUECODES_SCUFF = 28,
		CUECODES_SHOWLINEZ = 29,
		CUECODES_HIDELINEZ = 30,
		CUECODES_NONE = 31,
		CUECODES_CURSOR = 32,
		CUECODES_SHELF = 33,
		CUECODES_OTHERPET = 34,
		CUECODES_FOCUSSPRITE1 = 35,
		CUECODES_FOCUSSPRITE2 = 36,
		CUECODES_FOCUSSPRITE3 = 37,
		CUECODES_PERCENTCHANCE = 38,
		CUECODES_IFSOUNDADULT = 39,
		CUECODES_ISADOPTIONKIT = 40
	};

	enum fudgers_t {
		FUDGERS_ROTATION = 0,
		FUDGERS_ROLL = 1,
		FUDGERS_TILT = 2,
		FUDGERS_HEADROTATION = 3,
		FUDGERS_HEADTILT = 4,
		FUDGERS_HEADCOCK = 5,
		FUDGERS_REYELIDHEIGHT = 6,
		FUDGERS_LEYELIDHEIGHT = 7,
		FUDGERS_REYELIDTILT = 8,
		FUDGERS_LEYELIDTILT = 9,
		FUDGERS_EYETARGETX = 10,
		FUDGERS_EYETARGETY = 11,
		FUDGERS_XTRANS = 12,
		FUDGERS_YTRANS = 13,
		FUDGERS_SCALEX = 14,
		FUDGERS_SCALEY = 15,
		FUDGERS_SCALEZ = 16,
		FUDGERS_BALLSCALE = 17,
		FUDGERS_MASTERSCALE = 18,
		FUDGERS_REYESIZEXXX = 19,
		FUDGERS_LEYESIZEXXX = 20,
		FUDGERS_RARMSIZEXXX = 21,
		FUDGERS_LARMSIZEXXX = 22,
		FUDGERS_RLEGSIZEXXX = 23,
		FUDGERS_LLEGSIZEXXX = 24,
		FUDGERS_RHANDSIZEXXX = 25,
		FUDGERS_LHANDSIZEXXX = 26,
		FUDGERS_RFOOTSIZEXXX = 27,
		FUDGERS_LFOOTSIZEXXX = 28,
		FUDGERS_HEADSIZEXXX = 29,
		FUDGERS_BODYEXTEND = 30,
		FUDGERS_FRONTLEGEXTEND = 31,
		FUDGERS_HINDLEGEXTEND = 32,
		FUDGERS_FACEEXTEND = 33,
		FUDGERS_HEADENLARGE = 34,
		FUDGERS_HEADENLARGEBALANCE = 35,
		FUDGERS_EAREXTEND = 36,
		FUDGERS_FOOTENLARGE = 37,
		FUDGERS_FOOTENLARGEBALANCE = 38,
		FUDGERS_PREROTATION = 39,
		FUDGERS_PREROLL = 40,
		FUDGERS_ADDBALLZ0 = 41,
		FUDGERS_ADDBALLZFLOWER1 = 42,
		FUDGERS_ADDBALLZHEART2 = 43,
		FUDGERS_ADDBALLZQUESTION3 = 44,
		FUDGERS_ADDBALLZEXCLAMATION4 = 45,
		FUDGERS_ADDBALLZLIGHTBULBOFF5 = 46,
		FUDGERS_ADDBALLZSTICKMAN6 = 47,
		FUDGERS_ADDBALLZCROSSBONES7 = 48,
		FUDGERS_ADDBALLZLIGHTNING8 = 49,
		FUDGERS_ADDBALLZBROKENHEART9 = 50,
		FUDGERS_ADDBALLZSNOWONE10 = 51,
		FUDGERS_ADDBALLZSNOWTWO11 = 52,
		FUDGERS_ADDBALLZSNOWTHREE12 = 53,
		FUDGERS_ADDBALLZLIGHTBULBON13 = 54,
		FUDGERS_ADDBALLZTEARS14 = 55,
		FUDGERS_ADDBALLZODDLOVE15 = 56,
		FUDGERS_MORPH = 57,
		FUDGERS_BOTHEYELIDHEIGHTS = 58,
		FUDGERS_BOTHEYELIDTILTS = 59,
		FUDGERS_BOTHEYESIZES = 60,
		FUDGERS_BOTHARMSIZES = 61,
		FUDGERS_BOTHLEGSIZES = 62,
		FUDGERS_RIGHTLIMBSIZES = 63,
		FUDGERS_LEFTLIMBSIZES = 64,
		FUDGERS_ALLLIMBSIZES = 65,
		FUDGERS_BOTHHANDSIZES = 66,
		FUDGERS_BOTHFEETSIZES = 67,
		FUDGERS_RIGHTDIGITSIZES = 68,
		FUDGERS_LEFTDIGITSIZES = 69,
		FUDGERS_ALLDIGITSIZES = 70,
		FUDGERS_ALLFUDGERS = 71
	};

	scp_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, scp_t* p__root = 0);

private:
	void _read();
	void _clean_up();

public:
	~scp_t();

	class action_t : public kaitai::kstruct {

	public:

		action_t(kaitai::kstream* p__io, scp_t* p__parent = 0, scp_t* p__root = 0);

	private:
		void _read();
		void _clean_up();

	public:
		~action_t();

	private:
		bool f_scripts;
		std::vector<script_t*>* m_scripts;

	public:
		std::vector<script_t*>* scripts();

	private:
		uint32_t m_action_id;
		uint32_t m_script_count;
		uint32_t m_start_state;
		uint32_t m_end_state;
		uint32_t m_loop_modifier;
		uint16_t m_unknown1;
		uint16_t m_unknown2;
		uint16_t m_unknown3;
		uint16_t m_unknown4;
		uint32_t m_start_offset;
		scp_t* m__root;
		scp_t* m__parent;

	public:
		uint32_t action_id() const { return m_action_id; }
		uint32_t script_count() const { return m_script_count; }
		uint32_t start_state() const { return m_start_state; }
		uint32_t end_state() const { return m_end_state; }
		uint32_t loop_modifier() const { return m_loop_modifier; }
		uint16_t unknown1() const { return m_unknown1; }
		uint16_t unknown2() const { return m_unknown2; }
		uint16_t unknown3() const { return m_unknown3; }
		uint16_t unknown4() const { return m_unknown4; }
		uint32_t start_offset() const { return m_start_offset; }
		scp_t* _root() const { return m__root; }
		scp_t* _parent() const { return m__parent; }
	};

	class scripts_t : public kaitai::kstruct {

	public:

		scripts_t(kaitai::kstream* p__io, scp_t* p__parent = 0, scp_t* p__root = 0);

	private:
		void _read();
		void _clean_up();

	public:
		~scripts_t();

	private:
		std::vector<script_t*>* m_scripts;
		scp_t* m__root;
		scp_t* m__parent;

	public:
		std::vector<script_t*>* scripts() const { return m_scripts; }
		scp_t* _root() const { return m__root; }
		scp_t* _parent() const { return m__parent; }
	};

	class script_t : public kaitai::kstruct {

	public:

		script_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, scp_t* p__root = 0);

	private:
		void _read();
		void _clean_up();

	public:
		~script_t();

	private:
		uint32_t m_size;
		std::vector<verbs_t>* m_command;
		scp_t* m__root;
		kaitai::kstruct* m__parent;

	public:
		uint32_t size() const { return m_size; }
		std::vector<verbs_t>* command() const { return m_command; }
		scp_t* _root() const { return m__root; }
		kaitai::kstruct* _parent() const { return m__parent; }
	};

private:
	std::string m_intro;
	uint32_t m_total_states;
	uint32_t m_start_state;
	uint64_t m_unknown;
	uint32_t m_actioncount;
	std::vector<action_t*>* m_actions;
	uint32_t m_size_of_scripts;
	scripts_t* m_scripts;
	std::string m_ender;
	scp_t* m__root;
	kaitai::kstruct* m__parent;
	std::string m__raw_scripts;
	kaitai::kstream* m__io__raw_scripts;

public:
	std::string intro() const { return m_intro; }
	uint32_t total_states() const { return m_total_states; }
	uint32_t start_state() const { return m_start_state; }
	uint64_t unknown() const { return m_unknown; }
	uint32_t actioncount() const { return m_actioncount; }
	std::vector<action_t*>* actions() const { return m_actions; }
	uint32_t size_of_scripts() const { return m_size_of_scripts; }
	scripts_t* scripts() const { return m_scripts; }
	std::string ender() const { return m_ender; }
	scp_t* _root() const { return m__root; }
	kaitai::kstruct* _parent() const { return m__parent; }
	std::string _raw_scripts() const { return m__raw_scripts; }
	kaitai::kstream* _io__raw_scripts() const { return m__io__raw_scripts; }
};

#endif  // SCP_H_
