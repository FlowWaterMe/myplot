#pragma once
#pragma once

#include <QObject>
#include <QtGui/QPen>
#include <QtGui/QBrush>
#include <QtGui/QFont>

//#define TEST_DEBUG

// ���Ʊ�Ŀ��
#ifdef TEST_DEBUG
#define  COLUMN_WIDTH_120    120
#define  COLUMN_WIDTH_80     80
#else
#define  COLUMN_WIDTH_120    0
#define  COLUMN_WIDTH_80     0
#endif

#define VER_QRY_MAXNUM			3		// �汾��ѯ������

#define  CALIB_ORDER_ID_BEGIN   9000		// �������ʼOrderID
#define  QC_ORDER_ID_BEGIN		8000		// �ʿص���ʼOrderID

#define INVALID_ID (0xFFFFFFFF)

typedef unsigned int ASSAY_ID;
const ASSAY_ID gc_InvalidAssayID = 0;

typedef unsigned int RESULTUNIT_ID;
const RESULTUNIT_ID gc_InvalidUnitID = 0;

typedef unsigned int RESULTFLAG_ID;
const RESULTFLAG_ID gc_InvalidResultFlagID = 0;

// ������Ŀֵ��ID
typedef unsigned int RESULTDOMAIN_ID;
const RESULTDOMAIN_ID gc_InvalidResultDomainID = 0;

// ������ĿĬ��ֵID
typedef unsigned int DOMAINVALUE_ID;
const DOMAINVALUE_ID gc_InvalidDomainValueID = 0;

const QString MAXPARA = "...";
const int INVALIDPARA = 10000;


typedef unsigned int SAMPLE_ID;
const SAMPLE_ID gc_InvalidSampleID = 0;
Q_DECLARE_METATYPE(SAMPLE_ID);

typedef unsigned int REAGENT_ID;
typedef unsigned int REAGENTKIT_ID;
typedef unsigned int CALIBLIQUID_ID;
typedef unsigned int CALIBASSAYSET_ID;
typedef unsigned int QCLIQUID_ID;
typedef unsigned int QCASSAYSET_ID;

typedef unsigned int RACK_ID;
typedef unsigned int HOLE_ID;
typedef unsigned int PLATE_ID;

// ORDER_ID��ɽ��ܣ�
// ǰ6λ��ʾ�����գ���140608�� ��������ݱ�ʾ�����Ķ����ţ��Բ�����˵��SAMPLE_ID��
// ���ڲ�����˵��SAMPLE_ID��ORDER_ID��һһ��Ӧ�Ĺ�ϵ
// SAMPLE_IDΪ1ʱ��ORDER_IDΪ1406081
typedef unsigned int ORDER_ID;
const ORDER_ID gc_InvalidOrderID = 0;

typedef unsigned int TEST_ID;
const TEST_ID gc_InvalidTestID = 0;

typedef unsigned int REACTION_ID;
const REACTION_ID gc_InvalidReactionID = 0;

typedef unsigned int CALIBRESULT_ID;
const CALIBRESULT_ID gc_InvalidCalibResultID = 0;


typedef unsigned int VIR_ID;		// ���������̺�
typedef unsigned int PLATE_ID;		// �����̺ţ�һ̨����ͬʱ֧�ֵ���������
									//typedef unsigned int HOLE_ID;		// ������λ��

const int gc_iInvalidCuvetteIndex = -1;
const int gc_iInvalidCuvetteNo = 0;
inline int CuvetteIndexToNo(int iCuvetteIndex) { return (iCuvetteIndex + 1); };
inline int CuvetteNoToIndex(int iCuvetteNo) { return (iCuvetteNo - 1); };

//
const double gc_dAgeMin = 0;
const double gc_dAgeMax = 999;

const double gc_dLinearityMin = -999999999;
const double gc_dLinearityMax = 999999999;

const double gc_dResultMin = -999999999;
const double gc_dResultMax = 999999999;

const int g_TestPeriodTime = 500;		// ������ļ��ʱ�� ms

const int gc_DaysPerYear = 365;
const int gc_DaysPerMonth = 30;

// AD��������
const int gc_iADNormalRange_Min = 0;
const int gc_iADNormalRange_Max = 1000;

enum EResultUnitIndex
{
	eResultUnitIndex_mg_L = 0,  //mg/L
	eResultUnitIndex_ng_mL,     //ng/ml
	eResultUnitIndex_end,
};

enum EInstruModel
{
	eInstruModel_UnKnown,
	eInstruModel_PCL_Begin = 1,
	eInstruModel_PCL3000 = eInstruModel_PCL_Begin,
	eInstruModel_PCL3000S,
	eInstruModel_PCL_End = 100,

	eInstruModel_QDS_Begin = 101,
	eInstruModel_QDS1000 = eInstruModel_QDS_Begin,
	eInstruModel_QDS1200,
	eInstruModel_QDS_End = 200,

	eInstruModel_All = 1000,
};

enum EAssayClass
{
	eAssayClass_Unknown,
	eAssayClass_ScatterEmulsion, // ɢ�䷨���鵰��
	eAssayClass_DryFluorescence, // ��ʽӫ��
};
#define IsValidAssayClass(eAssayClass) ((eAssayClass >= eAssayClass_ScatterEmulsion) && (eAssayClass <= eAssayClass_DryFluorescence))

enum EAssayType
{
	eAssayType_Unknown = 0,
	eAssayType_Basic = 1 << 0,              //���Ե���Ŀ��������ĿCRP,SAA
	eAssayType_SubCell = 1 << 0,            //���������Ŀ������Ŀ�����������CRP������������ʹ��
	eAssayType_Test_Group = 1 << 2,         //����������������Ŀ
	eAssayType_Test_CustomGroup = 1 << 3,   //�Զ��������Ŀ
	eAssayType_Calcu = 1 << 4,
};
#define IsValidAssayType(eAssayType) ((eAssayType >= eAssayType_Basic) && (eAssayType <= eAssayType_Calcu))

enum EActionType
{
	eActionType_Unknown,
	eActionType_Normal,
	eActionType_RearSample,
	eActionType_Reserved,
};
#define IsValidActionType(eActionType) ((eActionType > eActionType_Unknown) && (eActionType < eActionType_Reserved))

enum ETestMethod
{
	eTestMethod_Unknown,
	eTestMethod_Endpoint,		//�յ㷨
	eTestMethod_FixTime,		//���㷨
	eTestMethod_Kinetic,		//���ʷ�
	eTestMethod_PeakValue,      //��ֵ
	eTestMethod_PeakArea,       //�����
};
#define IsValidTestMethod(eTestMethod) ((eTestMethod >= eTestMethod_Endpoint) && (eTestMethod <= eTestMethod_PeakArea))

enum ECalibMethod
{
	eCalibMethod_Unknown,
	eCalibMethod_KFactor,			//K���ӷ�
	eCalibMethod_OnePoint,			//��������
	eCalibMethod_TwoPoints,			//��������
	eCalibMethod_MultiPoints,		//�������
	eCalibMethod_LogitLog4P,		//Logit-log4P
	eCalibMethod_LogitLog5P,		//Logit-log5P
	eCalibMethod_Exponential,		//ָ������
	eCalibMethod_Polynomial,		//����ʽ
	eCalibMethod_Parabola,			//������
	eCalibMethod_Spline,			//��������
	eCalibMethod_Logistic4P,		//Logistic4P
	eCalibMethod_End = eCalibMethod_Logistic4P,
};
#define IsValidCalibMethod(eCalibMethod) ((eCalibMethod >= eCalibMethod_KFactor) && (eCalibMethod <= eCalibMethod_End))

//������Դ
enum ESampleSrcType
{
	eSampleSrcType_Unknown = -1,  // δ֪
	eSampleSrcType_Patient = 0,
	eSampleSrcType_QC,
	eSampleSrcType_Calib,
	eSampleSrcType_Reagent,
};
#define Int2SampleSrcType(Value) (((Value) >= eSampleSrcType_Patient && (Value) <= eSampleSrcType_Reagent) ? (ESampleSrcType)Value : eSampleSrcType_Patient) 


// ��������  Ѫ��...
enum ESampleLiquidType
{
	eSampleLiquidType_UnKnown = 0,
	eSampleLiquidType_Serum = 1 << 0,		// Ѫ��
	eSampleLiquidType_Blood = 1 << 1,		// ȫѪ(Ĭ��Ϊ����ȫѪ)
	eSampleLiquidType_PreDilu = 1 << 2,		// Ԥϡ��
	eSampleLiquidType_All = 1023
};
#define	Int2SampleLiquidType(Value) (((Value) >= eSampleLiquidType_UnKnown && (Value) <= eSampleLiquidType_PreDilu) ? (ESampleLiquidType)Value : eSampleLiquidType_Serum) //TODO: default eSampleLiquidType_Serum??


enum EReagentType
{
	eReagentType_NULL = -1,

	// iCRP �Լ�����
	eiCRPReagentType_Start = 0,
	eiCRPReagentType_Reaction = eiCRPReagentType_Start,		// Һ·��ϴҺ
	eiCRPReagentType_Cleaning,		// ��Ӧ����ϴҺ
	eiCRPReagentType_SAAEmulsion,	// SAA R2
	eiCRPReagentType_Emulsion,		// CRP R2
	eiCRPReagentType_WastLiq,		// ��Һ
	eiCRPReagentType_End = eiCRPReagentType_WastLiq,
};

enum EReagentVialType
{
	eReagentVialType_20 = 0,
	eReagentVialType_50 = 1,
};

enum EReagentStatus
{
	eReagentStatus_Normal = 0,      // ����
	eReagentStatus_Lack,            // ����
	eReagentStatus_UsedUp,          // �ľ�
	eReagentStatus_Expired,         // ����
};


// ����Ϣ��Ҫ�������������̳�ʼ��������λ��Ӧ��״̬
enum EHoleStatus
{
	eRackHoleStatus_Null = 0,		// ��λ��
	eRackHoleStatus_ExistSample,	// ��ǰλ�ô���������¼�������������޲���    
	eRackHoleStatus_Invalid,		// ���������� (����װ�ص�������/��ǰ�������ϵ������ظ�)
	eRackHoleStatus_EmptyCup,		// �ձ� (ɨ�赽����û����LIS���ҵ�������Ϣ)
	eRackHoleStatus_InvalidBarcode,	// ��Ч����
	eRackHoleStatus_PosConflict,	// ����λ�ó�ͻ (���������������Ϊʹ�ø�λ�ã�����ռ�ø�λ�õ�����������ɨ�赽�����벻һ��)
	eRackHoleStatus_Other           // ��eRackHoleStatus_EmptyCup���¶���ʾ��ǰλ����������¼
};


enum ESampleStatus
{
	eSampleStatus_InValid = -1,		// ��Ч
	eSampleStatus_BeforeTest = 0,		// ������  ��״̬
	eSampleStatus_Ready = 1,		// �Ѽ��� ������   ʵ״̬
	eSampleStatus_Block = 2,		// ����   
	eSampleStatus_Testing = 3,		// ������
	eSampleStatus_Success = 4,		// ���Գɹ�
	eSampleStatus_Failed = 5			// ����ʧ��
};
Q_DECLARE_METATYPE(ESampleStatus);
#define ConvertIntToESampleStatus(Value) (((Value) >= eSampleStatus_InValid && (Value) <= eSampleStatus_Failed) ? (ESampleStatus)Value : eSampleStatus_InValid) 

enum ETestStatus
{
	eTestStatus_Idle = -1,	// ��Ч
	eTestStatus_BeforeTest = 0,	// δ��
	eTestStatus_Block = 1,	// ����   
	eTestStatus_Testing = 2,	// ������
	eTestStatus_Success = 3,	// ���Գɹ�
	eTestStatus_Failed = 4,	// ����ʧ��
};
Q_DECLARE_METATYPE(ETestStatus);

#define  IsTestFinished(Value)	 (((Value) >= eTestStatus_Success && (Value) <= eTestStatus_Failed) ? true : false)
#define  IsTestSuccess(Value)	 (((Value) == eTestStatus_Success) ? true : false)
#define  IsTestBeforeTest(Value)	 (((Value) <= eTestStatus_Block) ? true : false)

// �ֹ�������Զ�����
enum EBarCodeSrcType
{
	eBarCode_Unknown = 0,
	eBarCode_Manual,
	eBarCode_Scan
};
#define Int2BarSrcType(Value) (((Value) >= eBarCode_Unknown && (Value) <= eBarCode_Scan) ? (EBarCodeSrcType)Value : eBarCode_Unknown) 

enum ESampleVialType  //���������� : ��Ѫ��
{
	eSampleVials_Unkown = 0,	// δ֪
	eSampleVials_BloodTube = 1,	// ��Ѫ��
	eSampleVials_StandardCup = 2,	// ��׼��
};
#define Int2SampleVialType(Value) (((Value) >= eSampleVials_Unkown && (Value) <= eSampleVials_StandardCup) ? (ESampleVialType)Value : eSampleVials_Unkown) 

// ������
enum EPlateType
{
	ePlateType_NULL = -1,
	ePlateType_Sample = 0,		// �����̣�ר��������
	ePlateType_Reagent = 1,		// �Լ��̣�ר�����Լ�
	ePlateType_Reaction = 2,		// ��Ӧ��
	ePlateType_Mixed = 3			// ����̣������������Լ�
};



typedef unsigned int Plate_ID;
const Plate_ID gc_InvalidPlateID = 0;
const Plate_ID gc_DefaultPlateID = 1;

typedef unsigned int Rack_ID;
const Rack_ID gc_InvalidRackID = 0;
const Rack_ID gc_DefaultRackID = 1;

typedef unsigned int Hole_ID;
const Hole_ID gc_InvalidHoleID = 0;
const Hole_ID gc_DefaultHoleID = 1;
















enum EQcConcLevel		// ���������һ��
{
	eQcConcLevel_Null = 0,
	eQcConcLevel_High,
	eQcConcLevel_Mid,
	eQcConcLevel_Low
};
Q_DECLARE_METATYPE(EQcConcLevel);

#define Int2QcConcLevel(Value) (((Value) > eQcConcLevel_Null && (Value) <= eQcConcLevel_Low) ? (EQcConcLevel)Value : eQcConcLevel_Low) 
#define IsConcLevelValid(Value) (((Value) <= eQcConcLevel_Null || (Value) > eQcConcLevel_Low) ? true : false) 

enum EResultCalcType
{
	eResultCalcType_Recent,		// ���һ�β��Խ��
	eResultCalcType_Average		// ���в��Ե�ƽ��ֵ
};

enum ETestOrderStatus
{
	eOrderStatus_NoneTested = 0,	// ȫ��δ����
	eOrderStatus_PartTested,		// �����Ѳ�
	eOrderStatus_AllTested,			// ȫ���Ѳ�
};



struct SPoint
{
	double x;
	double y;

	SPoint(double rx, double ry)
	{
		x = rx;
		y = ry;
	}
};

struct SCurvePoint
{
	SCurvePoint(double rx = 0, double ry = 0) :dYData(ry), dXData(rx) {};

	double dXData;
	double dYData;
};

enum EClickRule
{
	eClickRule_Not = 0,                 // û��
	eClickRule_Precise,                 // ��ȷ�������
	eClickRule_Round,                   // ��X������ƥ�����ߵ�
};

struct  SCurveParam
{
	QString sXName;                             // X�����
	QString sYName;                             // Y�����

	EClickRule eClickRule;                      // ������ͣ���ȷ����������ϵĵ���ʾ���������X��ƥ�䵽���ߵĵ�
	QFont   Plotfont;                           // ��ʾ��������
	bool    bIsDisplayLegend;                   // �Ƿ���ʾ��ʾ���
	QPen    CurveStylePen;                      // ���߷��
	int     XTickerNum;                         // X��̶���
	int     YTickerNum;                         // Y��̶���

	int     XLabelRotation;                     // �̶���ʾ�ַ���X��ļн�

	SCurveParam()
	{
		init();
	}

	void init()
	{
		sXName.clear();
		sYName.clear();
		Plotfont = QFont("Microsoft YaHei", 9);
		bIsDisplayLegend = false;
		CurveStylePen = QPen(QBrush(Qt::blue), 2, Qt::SolidLine);
		eClickRule = eClickRule_Round;
		XTickerNum = 10;
		YTickerNum = 8;
		XLabelRotation = 0;
	}
};

struct SCurvePlotData
{
	QVector<SCurvePoint> m_vecData;             // ���ߵ�����
	QString m_sCTStr;                           // ���ߵ�����(QDS1000��CT��ֵ��str��ʽ��C��value��T��value)
	QPen m_CurveStylePen;                         // ���߷��

	SCurvePlotData()
	{
		clear();
	}

	void clear() {
		m_vecData.clear();  m_sCTStr.clear(); m_CurveStylePen = QPen(QBrush(Qt::blue), 2, Qt::SolidLine);
	}
};



// �������״̬
enum ESamplePinStatus
{
	ePinStatus_UnKnown,		// δ֪
	ePinStatus_Idle,		// ���������
	ePinStatus_Busy,		// ������æ 
};

// ��������״̬
enum ESampleCuvetteStatus
{
	eSampleCuvetteStatus_Unknown,   // δ֪
	eSampleCuvetteStatus_Idle,
	eSampleCuvetteStatus_Testing,
};

// ��Ӧ����״̬
enum ECuvetteStatus
{
	eCuvetteStatus_UnKnown,         // δ֪
	eCuvetteStatus_Idle,
	eCuvetteStatus_Testing,

	//ichem������״̬�ٷ�Ϊ����
	eiChemCuvetteStatus_Idle = 100,	//����
	eiChemCuvetteStatus_AddR1,		//���Լ�1
	eiChemCuvetteStatus_AddS,		//������
	eiChemCuvetteStatus_AddR2,		//���Լ�2
	eiChemCuvetteStatus_AddR3,		//���Լ�3
	eiChemCuvetteStatus_Dilu,		//ϡ��
	eiChemCuvetteStatus_Clear,		//��Ӧ����ϴ
	eiChemCuvetteStatus_Finish,		//��ϴ���		
	eiChemCuvetteStatus_Dirty,		//�౭
};



enum EDicFieldType
{
	eDic_Begin = 0,
	eDic_Precision,					// ����
	eDic_SendOffice,				// �ͼ����
	eDic_SendDoc,					// �ͼ�ҽ��
	eDic_TestDoc,					// ����ҽ��
	eDic_CheckDoc,					// ���ҽ��
	eDic_ResultUnit,				// �����λ
	eDic_Diagnosis,					// ���
	eDic_ResultDesc,				// �������
	eDic_End,
};
#define IsDicFieldTypeValid(Value)		(((Value) >= eDic_Begin && (Value) < eDic_End) ? true : false)


enum EAgeUnit
{
	eAgeUnit_Null = -1,
	eAgeUnit_Year = 0,
	eAgeUnit_Month,
	eAgeUnit_Day
};


enum ESpeciesType
{
	eSpeciesType_Unknown = 0,
	eSpeciesType_Type1,// Human
	eSpeciesType_Type2,// 
	eSpeciesType_Type3,
	eSpeciesType_Type4,
	eSpeciesType_Type5,
	eSpeciesType_Type6,
	eSpeciesType_Type7,
	eSpeciesType_Type8,
	eSpeciesType_Type9,
};

enum EGender
{
	eGender_Null = -1,
	eGender_Man = 0,
	eGender_Woman,
};


enum EReferRule	// �ο���Χ���򣬶���ο���Χ�Ķ���
{
	eReferRule_Null = -1,
	eReferRule_Three,		// (, 0), [0, 10], (10, )
	eReferRule_Four,

};


enum EDataExportType
{
	eExport_AD = 0,
	eExport_Result,
	eExport_ADAndResult,
};

enum EUserPower
{
	ePower_Admin = 0,
	ePower_Research,
};

enum EOprType
{
	eOprType_Null,
	eOprType_Add,
	eOprType_Modify,
	eOprType_Save,
	eOprType_Delete,
	eOprType_Cancel,
	eOprType_View,
};

// ��Ȧ��һ������Ȧ����Ȧ����Ȧ
enum EPlateCircleType
{
	ePlate_InnerCircle = 0,		// ��Ȧ
	ePlate_MiddleCircle,		// ��Ȧ
	ePlate_OutCircle,			// ��Ȧ
};

struct SSamplePos
{
	unsigned int iSourceID;
	ESampleSrcType eSrcType;

	SSamplePos()
	{
		clear();
	}

	void clear()
	{
		iSourceID = INVALID_ID;
		eSrcType = eSampleSrcType_Patient;
	}

	bool operator == (SSamplePos rval)
	{
		if (iSourceID == rval.iSourceID && eSrcType == rval.eSrcType)
			return true;
		else
			return false;
	}

	bool operator != (SSamplePos rval)
	{
		if (iSourceID == rval.iSourceID && eSrcType == rval.eSrcType)
			return false;
		else
			return true;
	}

	SSamplePos& operator = (const SSamplePos& val)
	{
		iSourceID = val.iSourceID;
		eSrcType = val.eSrcType;
		return *this;
	}



	friend bool operator<(const SSamplePos &a, const SSamplePos &b)
	{
		if (a.eSrcType < b.eSrcType)
			return true;
		else if (a.eSrcType == b.eSrcType)
		{
			if (a.iSourceID < b.iSourceID)
				return true;
		}

		return false;
	}

};



enum EQcTimeType
{
	eQcType_RunTime,	// ʵʱ�ʿ�
						//eQcType_Day,		// �����ʿ�
						eQcType_Days,		// ����ʿ�
};

//TODO: other defines
const int g_ciMaxSampleHoleNo = 60;		// ������λ�ø���
const int g_ciMaxReagentHoleNo = 45;	// �Լ���λ�ø���
const int g_ciMaxReactionHoleNo = 120;	// ��Ӧ��λ�ø���

const int gc_iAbsorbVolumeForUltraClean = 48;
const int gc_iSoakTimeForUltraClean = 300;

enum ELisProtocolType
{
	eLisProtocolType_Unknown = 0,       // δ֪
	eLisProtocolType_HL7,               // ��׼HL7Э��
	eLisProtocolType_ASTM,              // ASTMЭ��
	eLisProtocolType_Custom             // �Զ���
};


//MC����Ĵ����豸����ӿ�
enum ESerialDevice
{
	eSerialDevice_MC = 0,	//���ذ崮���豸
	eSerialDevice_PP1,		//��Դ���ư��豸
	eSerialDevice_ALL,
};

//������
enum EBeepSound
{
	eBeepSound_Normal = 0,
	eBeepSound_Warning,
	eBeepSound_Alarm,
	eBeepSound_Off
};
Q_DECLARE_METATYPE(EBeepSound)

//LED
enum ELEDLightStatus
{
	eLed_Red_On = 0,
	eLed_Green_On,
	eLed_BLue_On,
	eLed_Orange_On,
	eLed_Red_Flicker,
	eLed_Green_Flicker,
	eLed_Blue_Flicker,
	eLed_Off,
};

//�ſ�����
enum EFlowDrainType
{
	eFlowDrain_CleanLiq = 0, //�ſշ�Ӧ����ϴҺ
	eFlowDrain_ReactionLiq,  //�ſ�Һ·��ϴҺ
	eFlowDrain_ALL,
};

const QString gc_sChannel1_CRP_Gain_ParamName = "Channel1_CRP_Gain";
const QString gc_sChannel2_CRP_Gain_ParamName = "Channel2_CRP_Gain";
const QString gc_sChannel3_CRP_Gain_ParamName = "Channel3_CRP_Gain";
const QString gc_sChannel4_CRP_Gain_ParamName = "Channel4_CRP_Gain";
const QString gc_sChannel1_SAA_Gain_ParamName = "Channel1_SAA_Gain";
const QString gc_sChannel2_SAA_Gain_ParamName = "Channel2_SAA_Gain";
const QString gc_sChannel3_SAA_Gain_ParamName = "Channel3_SAA_Gain";
const QString gc_sChannel4_SAA_Gain_ParamName = "Channel4_SAA_Gain";