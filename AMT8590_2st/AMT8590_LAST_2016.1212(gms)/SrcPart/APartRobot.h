// APartRobot.h: interface for the APartRobot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_APARTROBOT_H__F36F38B2_C7E5_4E2F_A33C_05C97C1D61A6__INCLUDED_)
#define AFX_APARTROBOT_H__F36F38B2_C7E5_4E2F_A33C_05C97C1D61A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PartFunction.h"
#include <vector>

// enum { JOB_PLACE, JOB_PICK, };
enum { JOB_PLACE, JOB_PICK, JOB_WAIT, };
//enum { JOB_BCR, JOB_PLACE, JOB_PICK, };
enum SORT_STEP
{
	SSTEP_NONE,
	SSTEP_PICK_READY,
	SSTEP_PICK_READY_CHK,

	SSTEP_PICK_PICKER_UP1,
	SSTEP_PICK_PICKER_UP1_CHK,
	SSTEP_PICK_ROBOT_Z_SAFETY,

	SSTEP_PICK_CALC,
	SSTEP_PICK_MDL_CALC,
//	SSTEP_PICK_MDL_MOVE_START,
	SSTEP_PICK_SAFETY,
	SSTEP_PICK_MOVE_TARGET,
	SSTEP_PICK_Z_DOWN,
	SSTEP_PICK_PICKER_DOWN,
	SSTEP_PICK_PICKER_DOWN_SKIP,
	SSTEP_PICK_MOVE_CALC,
	SSTEP_PICK_PICKER_DOWN_CHK,
	SSTEP_PICK_VACUUM_ON_ZDOWN,
	SSTEP_PICK_VACUUM_ON_ZDOWN_CHK,
	SSTEP_PICK_VACUUM_ON,
	SSTEP_PICK_VACUUM_ON_CHK,

	SSTEP_PICK_PICKER_UP2,
	SSTEP_PICK_PICKER_UP2_CHK,//20
	SSTEP_PICK_VACUUM_ON_CHK2,
	SSTEP_PICK_Z_UP,
	SSTEP_PICK_FINISH,

	SSTEP_PLACE_READY,
	SSTEP_PLACE_READY_CHK,
	
	SSTEP_PLACE_ROBOT_Z_SAFETY,
	SSTEP_PLACE_MDL_CALC,

	SSTEP_PLACE_MOVE_TARGET,
	SSTEP_PLACE_Z_DOWN,
	
	SSTEP_PLACE_PICKER_DOWN,//30
	SSTEP_PLACE_PICKER_DOWN_RETRY,
	SSTEP_PLACE_PICKER_DOWN_CHK,
	SSTEP_PLACE_VACUUM_OFF,
	SSTEP_PLACE_VACUUM_EJECTOR_ON,
	SSTEP_PLACE_VACUUM_EJECTOR_OFF,
	SSTEP_PLACE_VACUUM_OFF_CHK,
	SSTEP_PLACE_PICKER_UP2,
	SSTEP_PLACE_PICKER_UP2_CHK,
	SSTEP_PLACE_Z_UP,
	SSTEP_PLACE_FINISH,//40

	SSTEP_WAIT_START,
	SSTEP_CONV_WAIT_POS,
	SSTEP_CONV_WAIT_POS_READY,
	SSTEP_CONV_WAIT_POS_CHK,
	SSTEP_CONV_DVC_WAIT,

	SSTEP_UNLOAD_WAIT_POS,
	SSTEP_UNLOAD_WAIT_POS_READY,
	SSTEP_UNLOAD_WAIT_POS_CHK,
	SSTEP_UNLOAD_DVC_WAIT,

};
enum PICKER_STEP
{
	PSTEP_NONE,

	PSTEP_PICK_READY,
	PSTEP_PICK_READY_CHK,
	
	PSTEP_PICK_INSERT_BACK,
	PSTEP_PICK_INSERT_BACK_CHK,
	PSTEP_PICK_PICKER_UP1,
	PSTEP_PICK_PICKER_UP1_CHK,
	PSTEP_PICK_ROBOT_Z_SAFETY,

	PSTEP_PICK_MDL_CALC,
	PSTEP_PICK_MDL_BIN3,     //ybs

	PSTEP_PICK_MDL_ELVLD_XSAFETY,     //10
	PSTEP_PICK_MDL_ELVLD_ZSAFETY,

	PSTEP_PICK_MDL_MOVE_READY,
	PSTEP_PICK_MDL_MOVE_START,

	PSTEP_PICK_MOVE_TARGET,
	PSTEP_PICK_PICKER_DOWN,//15

	PSTEP_PICK_Z_DOWN,	
	PSTEP_PICK_Z_DOWN_CHK,

	PSTEP_PICK_VACUUM_ON_ZDOWN,
	PSTEP_PICK_VACUUM_ON,
	PSTEP_PICK_VACUUM_ON_CHK,//20

	PSTEP_PICK_Z_UP,
	PSTEP_PICK_PICKER_UP2,
	PSTEP_PICK_PICKER_UP2_CHK,
	PSTEP_PICK_FINISH_BEFORE,
	PSTEP_PICK_FINISH,   //25

	PSTEP_PLACE_READY,
	PSTEP_PLACE_READY_CHK,

	PSTEP_PLACE_INSERT_BACK,
	PSTEP_PLACE_INSERT_BACK_CHK,
	PSTEP_PLACE_PICKER_UP1,     //30
	PSTEP_PLACE_PICKER_UP1_CHK,
	PSTEP_PLACE_ROBOT_Z_SAFETY,
	PSTEP_PLACE_MDL_CALC,	
	PSTEP_PLACE_MDL_BIN3,     //ybs

	PSTEP_PLACE_MDL_ELVULD_XSAFETY,
	PSTEP_PLACE_MDL_ELVULD_ZSAFETY,

	PSTEP_PLACE_MDL_MOVE_READY,
	PSTEP_PLACE_MDL_MOVE_START,

	PSTEP_PLACE_MOVE_TARGET,
	PSTEP_PLACE_PICKER_DOWN,
	PSTEP_PLACE_Z_DOWN,
	PSTEP_PLACE_Z_DOWN_CHK,

	PSTEP_PLACE_VACUUM_OFF,
	PSTEP_PLACE_VACUUM_EJECTOR_ON,

	PSTEP_PLACE_Z_UP,

	PSTEP_PLACE_VACUUM_EJECTOR_OFF,
	PSTEP_PLACE_VACUUM_OFF_CHK,

	PSTEP_PLACE_PICKER_UP2,
	PSTEP_PLACE_PICKER_UP2_CHK,

	PSTEP_PLACE_FINISH_BEFORE,
	PSTEP_PLACE_FINISH,

};

enum FEEDER_STEP
{
	FEEDER_NONE,
	FEEDER_PICK_READY=10,
	FEEDER_PICK_Z1_SAFETY=20,
	FEEDER_PICK_Z2_SAFETY=30,
//	FEEDER_PICK_LOT_READY,
	FEEDER_PICK_MOVE=40,
	FEEDER_PICK_MOVE_DOWN=50,
	FEEDER_PICK_RBT_VACUUM=60,
	FEEDER_PICK_PLATE_VACUUM=70,
	FEEDER_PICK_RBT_VACUUM_CHK=80,
	FEEDER_PICK_RBT_VACUUM_DELAY=90,
	FEEDER_PICK_MOVE_UP=100,
	FEEDER_PICK_MOVE_UP_CHK=110,
	FEEDER_PICK_THROW_AWAY=120,
	FEEDER_PICK_THROW=130,
	FEEDER_PICK_THROW_DOWN=140,
	FEEDER_PICK_THROW_DOWN_VACUUM_OFF=150,
	FEEDER_PICK_THROW_DOWN_VACUUM_OFF_CHK=160,
	FEEDER_PICK_THROW_UP=170,
	FEEDER_PICK_THROW_Z_UP_CHK=180,
	FEEDER_PICK_THROW_Z_FINISH=190,



	FEEDER_PICK_PLACE_READY=200,
	FEEDER_PICK_FINISH=210,



	FEEDER_PLACE_READY=300,
	FEEDER_PLACE_VACUUM_ON_CHK=310,
	FEEDER_PLACE_MOVE_CHK=320,


	FEEDER_PLACE_MOVE=330,
	FEEDER_PLACE_ERROR_MOVE=340,

	FEEDER_PLACE_Z_DOWN=350,
	FEEDER_PLACE_VACUUM_OFF=360,
	FEEDER_PLACE_VACUUM_OFF_CHK=370,

	FEEDER_PLACE_UP=380,
	FEEDER_PLACE_UP_CHK=390,
	FEEDER_PLACE_FINISH=400,
	FEEDER_PLACE_FINISH_READY=410,
	FEEDER_PLACE_FINISH_READY_CHK=420,
};

enum BCR_FEEDER_STEP
{
	BCR_FEEDER_NONE,
	BCR_FEEDER_PICK_READY,
	BCR_FEEDER_PLACE_VACUUM_ON_CHK,

	BCR_FEEDER_PLACE_MOVE,
	BCR_FEEDER_PLACE_Z_DOWN,
	BCR_FEEDER_PLACE_VACUUM_OFF,
	BCR_FEEDER_PLACE_VACUUM_OFF_CHK,

	BCR_FEEDER_PLACE_UP,
	BCR_FEEDER_PLACE_UP_CHK,

	BCR_FEEDER_PLACE_FINISH,
};

enum BCR1_STEP
{
	BCR1_NONE,
	BCR1_PICK_LABEL_READY=10,
	BCR1_PICK_Z1_SAFETY=20,
	BCR1_PICK_Z2_SAFETY=30,
	BCR1_PICK_LABEL_TOP_CHK=40,
	BCR1_PICK_LABEL_TOP_LEFT_BACKWPRD=50,
	BCR1_PICK_LABEL_TOP_LEFT_BACKWPRD_CHK=60,
	BCR1_PICK_LABEL_TOP_RIGHT_BACKWPRD=70,
	BCR1_PICK_LABEL_TOP_RIGHT_BACKWPRD_CHK=80,
	BCR1_PICK_LABEL_BTM_CHK=90,
	BCR1_PICK_LABEL_BTM_LEFT_BACKWPRD=100,
	BCR1_PICK_LABEL_BTM_LEFT_BACKWPRD_CHK=110,
	BCR1_PICK_LABEL_BTM_RIGHT_BACKWPRD=120,
	BCR1_PICK_LABEL_BTM_RIGHT_BACKWPRD_CHK=130,
	BCR1_PICK_LABEL_ROTATE_CHK=140,
	BCR1_PICK_R1_SAFETY=150,
	BCR1_PICK_R2_SAFETY=160,
	BCR1_PICK_LABEL_MOVE_READY_POS=170,
	BCR1_PICK_LABEL_MOVE_READY=180,
	BCR1_PICK_LABEL_PICK_READY=190,
	BCR1_PICK_LABEL_DOWN=200,
	BCR1_PICK_LABEL_DOWN_CHK=210,
	BCR1_PICK_LABEL_VACUUM=220,
	BCR1_PICK_LABEL_VACUUM_CHK=230,
	BCR1_PICK_LABEL_UP=240,
	BCR1_PICK_LABEL_UP_VACUUM_CHK=250,
	BCR1_PICK_LABEL_FINISH=270,

	BCR1_PLACE_LABEL_READY=300,
	BCR1_PLACE_LABEL_X_READY=310,
	BCR1_PLACE_LABEL_READY2=320,
	BCR1_PLACE_LABEL_ROLLER_X_POS=330,

	BCR1_PLACE_LABEL_DOWN=340,
	BCR1_PLACE_LABEL_PUSH=350,
	BCR1_PLACE_LABEL_XPLACE=360,
	BCR1_PLACE_LABEL_PUSH_CHK=370,
	BCR1_PLACE_LABEL_PUSH_VACUUM=380,	
	BCR1_PLACE_LABEL_VACUUM_CHK=390,
	BCR1_PLACE_LABEL_PULL=400,
	BCR1_PLACE_LABEL_PULL_CHK=410,
	BCR1_PLACE_LABEL_VACUUM_RECHK=420,
	BCR1_PLACE_LABEL_XDOWN_BACK=430,
	BCR1_PLACE_LABEL_UP=450,
	BCR1_PLACE_LABEL_SAFETY=460,
	BCR1_PLACE_LABEL_FINISH=470,
};

enum BCR2_STEP
{
	BCR2_NONE=0,
	BCR2_PICK_LABEL_READY=10,
	BCR2_PICK_Z1_SAFETY=20,
	BCR2_PICK_Z2_SAFETY=30,
	BCR2_PICK_LABEL_TOP_CHK=40,
	BCR2_PICK_LABEL_TOP_LEFT_BACKWPRD=50,
	BCR2_PICK_LABEL_TOP_LEFT_BACKWPRD_CHK=60,
	BCR2_PICK_LABEL_TOP_RIGHT_BACKWPRD=70,
	BCR2_PICK_LABEL_TOP_RIGHT_BACKWPRD_CHK=80,
	BCR2_PICK_LABEL_BTM_CHK=90,
	BCR2_PICK_LABEL_BTM_LEFT_BACKWPRD=100,
	BCR2_PICK_LABEL_BTM_LEFT_BACKWPRD_CHK=110,
	BCR2_PICK_LABEL_BTM_RIGHT_BACKWPRD=120,
	BCR2_PICK_LABEL_BTM_RIGHT_BACKWPRD_CHK=130,
	BCR2_PICK_LABEL_ROTATE_CHK=140,
	BCR2_PICK_R1_SAFETY=150,
	BCR2_PICK_R2_SAFETY=160,
	BCR2_PICK_LABEL_MOVE_READY_POS=170,
	BCR2_PICK_LABEL_MOVE_READY=180,
	BCR2_PICK_LABEL_PICK_READY=190,
	BCR2_PICK_LABEL_DOWN=200,
	BCR2_PICK_LABEL_DOWN_CHK=210,
	BCR2_PICK_LABEL_VACUUM=220,
	BCR2_PICK_LABEL_VACUUM_CHK=230,
	BCR2_PICK_LABEL_UP=240,
	BCR2_PICK_LABEL_UP_VACUUM_CHK=250,
	BCR2_PICK_LABEL_FINISH=270,

	BCR2_PLACE_LABEL_READY=300,
	BCR2_PLACE_LABEL_X_READY=310,
	BCR2_PLACE_LABEL_READY2=320,
	BCR2_PLACE_LABEL_ROLLER_X_POS=330,


	BCR2_PLACE_LABEL_DOWN=340,
	BCR2_PLACE_LABEL_PUSH=350,
	BCR2_PLACE_LABEL_XPLACE=360,
	BCR2_PLACE_LABEL_PUSH_CHK=370,
	BCR2_PLACE_LABEL_PUSH_VACUUM=380,	
	BCR2_PLACE_LABEL_VACUUM_CHK=390,
	BCR2_PLACE_LABEL_PULL=400,
	BCR2_PLACE_LABEL_PULL_CHK=410,
	BCR2_PLACE_LABEL_VACUUM_RECHK=420,
	BCR2_PLACE_LABEL_XDOWN_BACK=430,
	BCR2_PLACE_LABEL_UP=450,
	BCR2_PLACE_LABEL_SAFETY=460,
	BCR2_PLACE_LABEL_FINISH=470,
};

enum TVISION_STEP
{
	TVISION_NONE=0,
	TVISION_READY=10,
	TVISION_TEST_READY=20,
	TVISION_TEST1_READY=30,
	TVISION_TEST1_COMM=40,

	TVISION_TEST1_RESULT=50,
	TVISION_TEST2_READY=60,
	TVISION_TEST2_COMM=70,
	TVISION_TEST2_RESULT=80,
	TVISION_FINISH=100,
};

enum ELV_STEP
{
	ELV_NONE,
	ELV_READY,
	ELV_BUFFER_CHK,
	ELV_MDL_CHK,
	ELV_TOP_DATA_CHK,
	ELV_BTM_SAFETY_CHK,
	ELV_BTM_MOVE,
	ELV_CON_MDL_CHK,
	ELV_TOP_MDL_CHK,
	ELV_BTM_MDL_READY,
	ELV_BTM_MOVE_READY,
	ELV_BTM_MOVE_CLAMP_OFF_REQ,
	ELV_BTM_MOVE_CLAMP_OFF,
	ELV_BTM_MOVE_CLAMP_OFF_CHK,
	ELV_BTM_MOVE_SGN_CLAMP_OFF,
	ELV_BTM_MOVE_FINISH,
	ELV_TOP_MOVE,

	ELV_FINISH,
};

enum BVISION_STEP
{
	BVISION_NONE,
	BVISION_PICK_READY=10,
	BVISION_PICK_SAFETY=20,
	BVISION_PICK_PUSHER_MDL=30,
	BVISION_PICK_MOVE_POS=40,

	BVISION_PICK_PICKER_DOWN=50,
	BVISION_PICK_Z_DOWN=60,
	BVISION_PICK_VACUUM_ON_ZDOWN=70,
	BVISION_PICK_PULL_MDL=80,

	BVISION_PICK_Z_DOWN_CHK=90,
	BVISION_PICK_VACUUM=100,
	BVISION_PICK_VACUUM_CHK=110,
	BVISION_PICK_PICKER_UP=120,
	BVISION_PICK_Z_UP=130,
	BVISION_PICK_PICKER_UP_CHK=140,
	BVISION_PICK_EMPTY_CHK=150,
	BVISION_PICK_FINISH=160,
	BVISION_VISION_POS=170,
	BVISION_VISION1_CHK=180,
	BVISION_VISION1_COMM=190,
	BVISION_VISION2_CHK=200,
	BVISION_VISION2_COMM=210,
	BVISION_VISION_RESULT=220,

	BVISION_PLACE_READY=300,
	BVISION_PLACE_MOVE_CALC=310,
	BVISION_PLACE_MOVE=320,
	BVISION_PLAC_MOVE_PICKER_DOWN=330,
	BVISION_PLAC_MOVE_Z_DOWN=340,
	BVISION_PLACE_MOVE_PICKER_DOWN_CHK=350,
	BVISION_PLACE_VACUUM=360,
	BVISION_PLACE_UP=370,
	BVISION_PLACE_UP_CHK=380,
	BVISION_PLACE_VACUUM_CHK=390,
	BVISION_PLACE_FINISH=400

//	BVISION_VISION_PASS_CHK,
//	BVISION_PLACE_MOVE_CONVEYOR,
//	BVISION_PLAC_MOVE_CONVEYOR_PICKER_DOWN,
//	BVISION_PLAC_MOVE_CONVEYOR_Z_DOWN,
//	BVISION_PLACE_MOVE_CONVEYOR_PICKER_DOWN_CHK,
//	BVISION_PLACE_CONVEYOR_VACUUM,
//	BVISION_PLACE_CONVEYOR_UP,
//	BVISION_PLACE_CONVEYOR_VACUUM_CHK,
//	BVISION_PLACE_CONVEYOR_FINISH,
//	BVISION_PLACE_MOVE_REJECT,
//	BVISION_PLACE_MOVE_REJECT_POS,
//	BVISION_PLAC_MOVE_REJECT_PICKER_DOWN,
//	BVISION_PLAC_MOVE_REJECT_Z_DOWN,
//	BVISION_PLACE_MOVE_CONVEYOR_REJECT_DOWN_CHK,
//	BVISION_PLACE_REJECT_VACUUM,
//	BVISION_PLACE_REJECT_UP,
//	BVISION_PLACE_REJECT_VACUUM_CHK,
//	BVISION_PLACE_FINISH,
};

enum CONVEYOR_STEP
{
	CONV_NONE,
	CONV_READY,
	CONV_MDL_CHK,
	CONV_MOVE,
	CONV_MOVE_CHK,
	CONV_OUT_CHK,
	CONV_FINISH,
};

struct stJobPicker
{
	int bPick;
	int iRobotFirst;
	int iRobotSecond;

	int iPosFirst;

	PICKER_STEP picker_step;
	FEEDER_STEP feeder_step;
	BCR_FEEDER_STEP bcr_feeder_step;
	BCR1_STEP 	bcr1_step; 
	BCR2_STEP 	bcr2_step;
	TVISION_STEP	tvis_step;
	BVISION_STEP	bvis_step;
	CONVEYOR_STEP	conv_step;
	ELV_STEP	elv_step;


	bool bUpSkip;

	stJobPicker()
	{
		bPick = JOB_PICK;
		iRobotFirst = -1;
		iRobotSecond = -1;

		iPosFirst = -1;

		picker_step = PSTEP_NONE;
		bUpSkip = false;
	}
	void Set( int _bPick, int _iRobotFirst, int _iRobotSecond, int _iPosFirst )
	{
		if (_iPosFirst >= MPOS_INDEX_PMACHINE && _iPosFirst < MAX_MPOS_INDEX )
		{
			bPick = _bPick;
			iRobotFirst = _iRobotFirst;
			iRobotSecond = _iRobotSecond;
			iPosFirst = _iPosFirst;
			
			if( _iPosFirst > MPOS_INDEX_PMACHINE && _iPosFirst <= MPOS_INDEX_DENSITY)
				feeder_step = FEEDER_PICK_READY;
			else if( _iPosFirst > MPOS_INDEX_DENSITY && _iPosFirst <= MPOS_INDEX_BCR1_FEEDER + 1)
				bcr1_step = BCR1_PICK_LABEL_READY;
			else if( _iPosFirst > MPOS_INDEX_BCR1_FEEDER && _iPosFirst <= MPOS_INDEX_BCR2_FEEDER + 1)
				bcr2_step = BCR2_PICK_LABEL_READY;
			else if( _iPosFirst > MPOS_INDEX_BCR2_LOAD && _iPosFirst <= (MPOS_INDEX_TOPVISION + 1))
				tvis_step = TVISION_READY;
			else if( _iPosFirst > MPOS_INDEX_TOPVISION && _iPosFirst <= (MPOS_INDEX_UNLOAD+1))
				bvis_step = BVISION_PICK_READY;
			else if( _iPosFirst > MPOS_INDEX_CONVEYOR && _iPosFirst <= MPOS_INDEX_ELV)
				elv_step = ELV_READY;
//			
			if( _bPick == JOB_PLACE )
			{
				if( _iPosFirst > MPOS_INDEX_PMACHINE && _iPosFirst <= MPOS_INDEX_DENSITY)
					feeder_step = FEEDER_PLACE_READY;
				if( _iPosFirst > MPOS_INDEX_DENSITY && _iPosFirst <= (MPOS_INDEX_BCR1_LOAD + 1) )
					bcr1_step = BCR1_PLACE_LABEL_READY;
				else if( _iPosFirst > MPOS_INDEX_BCR1_LOAD && _iPosFirst <= (MPOS_INDEX_BCR2_LOAD + 1) )
					bcr2_step = BCR2_PLACE_LABEL_READY;
				else if( _iPosFirst > MPOS_INDEX_BCR2_LOAD && _iPosFirst <= (MPOS_INDEX_TOPVISION + 1) )
					tvis_step = TVISION_READY;
				else if( _iPosFirst > MPOS_INDEX_TOPVISION && _iPosFirst <= (MPOS_INDEX_UNLOAD + 1 ) )
					bvis_step = BVISION_PLACE_READY;
				else if( _iPosFirst > MPOS_INDEX_UNLOAD && _iPosFirst <= (MPOS_INDEX_CONVEYOR + 1 ) )
					bvis_step = BVISION_PLACE_READY;
				else if( _iPosFirst > MPOS_INDEX_CONVEYOR && _iPosFirst <= MPOS_INDEX_ELV)
					bvis_step = BVISION_PLACE_READY;
				else if( _iPosFirst > MPOS_INDEX_ULD_NEXT && _iPosFirst <= (MPOS_INDEX_REJECT + 1 ) )
					bvis_step = BVISION_PLACE_READY;
			}
		}
	}
	
	ENUM_LABEL_POSITION GetPosByTarget()
	{
		if	   ( iPosFirst < MPOS_INDEX_DENSITY_FEEDER )	return MPOS_INDEX_PMACHINE;
		else if( iPosFirst < MPOS_INDEX_DENSITY )			return MPOS_INDEX_DENSITY_FEEDER;
		else if( iPosFirst < MPOS_INDEX_BCR1_FEEDER )		return MPOS_INDEX_DENSITY;
		else if( iPosFirst < MPOS_INDEX_BCR1_LOAD )			return MPOS_INDEX_BCR1_FEEDER;
		else if( iPosFirst < MPOS_INDEX_BCR2_FEEDER )		return MPOS_INDEX_BCR1_LOAD;
		else if( iPosFirst < MPOS_INDEX_BCR2_LOAD )			return MPOS_INDEX_BCR2_FEEDER;
		else if( iPosFirst < MPOS_INDEX_TOPVISION )			return MPOS_INDEX_BCR2_LOAD;
		else if( iPosFirst < MPOS_INDEX_UNLOAD )			return MPOS_INDEX_TOPVISION;
		else if( iPosFirst < MPOS_INDEX_CONVEYOR )			return MPOS_INDEX_UNLOAD;
// 		else if( iPosFirst < MPOS_INDEX_ELV )				return MPOS_INDEX_TOPVISION;
		else if( iPosFirst < MPOS_INDEX_ELV )				return MPOS_INDEX_CONVEYOR;
		else if( iPosFirst < MPOS_INDEX_ULD_ELV )			return MPOS_INDEX_CONVEYOR;
		else if( iPosFirst < MPOS_INDEX_ULD_ELV )			return MPOS_INDEX_ELV;
		else if( iPosFirst < MPOS_INDEX_ULD_NEXT )			return MPOS_INDEX_ULD_ELV;
		else if( iPosFirst < MPOS_INDEX_REJECT )			return MPOS_INDEX_ULD_NEXT;
		else												return MPOS_INDEX_REJECT;
	}
	int GetPosPartByTarget()
	{
		return GetPosByTarget();
	}

};

ENUM_LABEL_POSITION GetPosByTarget( int nTarget );
int GetPosPartByTarget( int nTarget );

//struct stJobPicker
//{
//	int bPick;
//	int iRobotFirst;
//	int iRobotSecond;
//	int iPosFirst;
//
//	FEEDER_STEP feeder_step;
//	bool bUpSkip;
//
//	stJobPicker()
//	{
//		bPick = JOB_PICK;
//		iRobotFirst = -1;
//		iRobotSecond = -1;
//		iPosFirst = -1;
//
//		feeder_step = FEEDER_NONE;
//		bUpSkip = false;
//	}
//	void Set( int _bPick, int _iRobotFirst, int _iRobotSecond, int _iPosFirst )
//	{
//		bPick = _bPick;
//		iRobotFirst = _iRobotFirst;
//		iRobotSecond = _iRobotSecond;
//		iPosFirst = _iPosFirst;
//		feeder_step = FEEDER_PICK_READY;
//		if( _bPick == JOB_PLACE ) feeder_step = FEEDER_PLACE_READY;
//	}	
//
//};


class APicker
{
public:
	APicker();
	virtual ~APicker();

	AModule& GetModule() { return m_mdl; }
	void SetModule( AModule mdl ) { m_mdl = mdl; }

	void SetLabel(ALabel ldl ) { m_ldl = ldl; }
	ALabel& GetLabel() { return m_ldl; }

	void SetBcrLabel(ABcrLabel bcrldl ) { m_bcrldl = bcrldl; }
	ABcrLabel& GetBcrLabel() { return m_bcrldl; }

	void SetTopVision(ATopVision top ) { m_topldl = top; }
	ATopVision& GetTopVision() { return m_topldl; }

	void SetUnloadRbt(ABtmVision btm ) { m_btmldl = btm; }
	ABtmVision& GetUnloadRbt() { return m_btmldl; }


protected:
	AModule	m_mdl;
	ALabel m_ldl;
	ABcrLabel m_bcrldl;
	ATopVision m_topldl;
	ABtmVision m_btmldl;

	int m_nTargetPos;
	int m_nPickPos;
	CString m_strCapa;
};

enum	{ PICKER_CNT = 2, };

class APartRobot  
{
public:
	APartRobot();
	virtual ~APartRobot();

	bool IsLabelPicking();
	bool IsBcr1Picking();
	bool IsBcr2Picking();
	bool IsTopVisionPicking();
	bool IsUnloadPicking();
	bool IsElvChecking();
	bool IsPicking();

	int GetJobCount() { return m_vecJob.size(); }
	void AddJob( int bPick, int iRobotFirst, int iRobotSecond, int iPosFirst);
	stJobPicker& GetFirstJob();
	stJobPicker& GetJob( int iIdx );

	void EraseFirstJob();
	APicker& GetPicker( int iIdx ) { return m_Picker[iIdx]; }
	int GetModuleCnt();

protected:
	APicker	m_Picker[PICKER_CNT];

	std::vector<stJobPicker>	m_vecJob;
	stJobPicker					m_dummyJob;
};

extern APartRobot g_robot[10];
//extern APartRobot g_sorter_robot;
//extern APartRobot g_density_robot;
//extern APartRobot g_bcrfeeder_robot;
//extern APartRobot g_bcr1_robot;
//extern APartRobot g_bcr2_robot;
//extern APartRobot g_vision_robot;
//extern APartRobot g_unload_robot;
//extern APartRobot g_unload_elv;
//extern APartRobot g_conveyor_robot;
//

#endif // !defined(AFX_APARTROBOT_H__F36F38B2_C7E5_4E2F_A33C_05C97C1D61A6__INCLUDED_)
