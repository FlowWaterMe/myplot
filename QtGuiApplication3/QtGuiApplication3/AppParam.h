#pragma once
#pragma once

#include <QObject>
#include <QtGui/QPen>
#include <QtGui/QBrush>
#include <QtGui/QFont>

//#define TEST_DEBUG

// 控制表的宽度
#ifdef TEST_DEBUG
#define  COLUMN_WIDTH_120    120
#define  COLUMN_WIDTH_80     80
#else
#define  COLUMN_WIDTH_120    0
#define  COLUMN_WIDTH_80     0
#endif

#define VER_QRY_MAXNUM			3		// 版本查询最大个数

#define  CALIB_ORDER_ID_BEGIN   9000		// 定标的起始OrderID
#define  QC_ORDER_ID_BEGIN		8000		// 质控的起始OrderID

#define INVALID_ID (0xFFFFFFFF)

typedef unsigned int ASSAY_ID;
const ASSAY_ID gc_InvalidAssayID = 0;

typedef unsigned int RESULTUNIT_ID;
const RESULTUNIT_ID gc_InvalidUnitID = 0;

typedef unsigned int RESULTFLAG_ID;
const RESULTFLAG_ID gc_InvalidResultFlagID = 0;

// 定性项目值域ID
typedef unsigned int RESULTDOMAIN_ID;
const RESULTDOMAIN_ID gc_InvalidResultDomainID = 0;

// 定性项目默认值ID
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

// ORDER_ID组成介绍：
// 前6位表示年月日，如140608， 后面的数据表示真正的订单号（对病人来说即SAMPLE_ID）
// 对于病人来说，SAMPLE_ID和ORDER_ID是一一对应的关系
// SAMPLE_ID为1时，ORDER_ID为1406081
typedef unsigned int ORDER_ID;
const ORDER_ID gc_InvalidOrderID = 0;

typedef unsigned int TEST_ID;
const TEST_ID gc_InvalidTestID = 0;

typedef unsigned int REACTION_ID;
const REACTION_ID gc_InvalidReactionID = 0;

typedef unsigned int CALIBRESULT_ID;
const CALIBRESULT_ID gc_InvalidCalibResultID = 0;


typedef unsigned int VIR_ID;		// 虚拟样本盘号
typedef unsigned int PLATE_ID;		// 样本盘号，一台机器同时支持的样本盘数
									//typedef unsigned int HOLE_ID;		// 样本孔位置

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

const int g_TestPeriodTime = 500;		// 两个点的间隔时间 ms

const int gc_DaysPerYear = 365;
const int gc_DaysPerMonth = 30;

// AD正常区间
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
	eAssayClass_ScatterEmulsion, // 散射法胶乳蛋白
	eAssayClass_DryFluorescence, // 干式荧光
};
#define IsValidAssayClass(eAssayClass) ((eAssayClass >= eAssayClass_ScatterEmulsion) && (eAssayClass <= eAssayClass_DryFluorescence))

enum EAssayType
{
	eAssayType_Unknown = 0,
	eAssayType_Basic = 1 << 0,              //测试单项目，含单项目CRP,SAA
	eAssayType_SubCell = 1 << 0,            //测试组合项目的子项目，如二联卡的CRP，和组合项配合使用
	eAssayType_Test_Group = 1 << 2,         //二联卡，三联卡项目
	eAssayType_Test_CustomGroup = 1 << 3,   //自定义组合项目
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
	eTestMethod_Endpoint,		//终点法
	eTestMethod_FixTime,		//两点法
	eTestMethod_Kinetic,		//速率法
	eTestMethod_PeakValue,      //峰值
	eTestMethod_PeakArea,       //峰面积
};
#define IsValidTestMethod(eTestMethod) ((eTestMethod >= eTestMethod_Endpoint) && (eTestMethod <= eTestMethod_PeakArea))

enum ECalibMethod
{
	eCalibMethod_Unknown,
	eCalibMethod_KFactor,			//K因子法
	eCalibMethod_OnePoint,			//单点线性
	eCalibMethod_TwoPoints,			//两点线性
	eCalibMethod_MultiPoints,		//多点线性
	eCalibMethod_LogitLog4P,		//Logit-log4P
	eCalibMethod_LogitLog5P,		//Logit-log5P
	eCalibMethod_Exponential,		//指数函数
	eCalibMethod_Polynomial,		//多项式
	eCalibMethod_Parabola,			//抛物线
	eCalibMethod_Spline,			//样条曲线
	eCalibMethod_Logistic4P,		//Logistic4P
	eCalibMethod_End = eCalibMethod_Logistic4P,
};
#define IsValidCalibMethod(eCalibMethod) ((eCalibMethod >= eCalibMethod_KFactor) && (eCalibMethod <= eCalibMethod_End))

//样本来源
enum ESampleSrcType
{
	eSampleSrcType_Unknown = -1,  // 未知
	eSampleSrcType_Patient = 0,
	eSampleSrcType_QC,
	eSampleSrcType_Calib,
	eSampleSrcType_Reagent,
};
#define Int2SampleSrcType(Value) (((Value) >= eSampleSrcType_Patient && (Value) <= eSampleSrcType_Reagent) ? (ESampleSrcType)Value : eSampleSrcType_Patient) 


// 样本类型  血清...
enum ESampleLiquidType
{
	eSampleLiquidType_UnKnown = 0,
	eSampleLiquidType_Serum = 1 << 0,		// 血清
	eSampleLiquidType_Blood = 1 << 1,		// 全血(默认为肝素全血)
	eSampleLiquidType_PreDilu = 1 << 2,		// 预稀释
	eSampleLiquidType_All = 1023
};
#define	Int2SampleLiquidType(Value) (((Value) >= eSampleLiquidType_UnKnown && (Value) <= eSampleLiquidType_PreDilu) ? (ESampleLiquidType)Value : eSampleLiquidType_Serum) //TODO: default eSampleLiquidType_Serum??


enum EReagentType
{
	eReagentType_NULL = -1,

	// iCRP 试剂类型
	eiCRPReagentType_Start = 0,
	eiCRPReagentType_Reaction = eiCRPReagentType_Start,		// 液路清洗液
	eiCRPReagentType_Cleaning,		// 反应杯清洗液
	eiCRPReagentType_SAAEmulsion,	// SAA R2
	eiCRPReagentType_Emulsion,		// CRP R2
	eiCRPReagentType_WastLiq,		// 废液
	eiCRPReagentType_End = eiCRPReagentType_WastLiq,
};

enum EReagentVialType
{
	eReagentVialType_20 = 0,
	eReagentVialType_50 = 1,
};

enum EReagentStatus
{
	eReagentStatus_Normal = 0,      // 正常
	eReagentStatus_Lack,            // 不足
	eReagentStatus_UsedUp,          // 耗尽
	eReagentStatus_Expired,         // 过期
};


// 该信息主要用于描述样本盘初始化各个空位对应的状态
enum EHoleStatus
{
	eRackHoleStatus_Null = 0,		// 空位置
	eRackHoleStatus_ExistSample,	// 当前位置存在样本记录，包括有样本无测试    
	eRackHoleStatus_Invalid,		// 样本不可用 (与已装载到样本盘/当前样本架上的条码重复)
	eRackHoleStatus_EmptyCup,		// 空杯 (扫描到条码没有在LIS中找到样本信息)
	eRackHoleStatus_InvalidBarcode,	// 无效条码
	eRackHoleStatus_PosConflict,	// 样本位置冲突 (如果已有样本设置为使用该位置，并且占用该位置的样本条码与扫描到的条码不一致)
	eRackHoleStatus_Other           // 从eRackHoleStatus_EmptyCup向下都表示当前位置无样本记录
};


enum ESampleStatus
{
	eSampleStatus_InValid = -1,		// 无效
	eSampleStatus_BeforeTest = 0,		// 已申请  虚状态
	eSampleStatus_Ready = 1,		// 已加载 、待测   实状态
	eSampleStatus_Block = 2,		// 阻塞   
	eSampleStatus_Testing = 3,		// 测试中
	eSampleStatus_Success = 4,		// 测试成功
	eSampleStatus_Failed = 5			// 测试失败
};
Q_DECLARE_METATYPE(ESampleStatus);
#define ConvertIntToESampleStatus(Value) (((Value) >= eSampleStatus_InValid && (Value) <= eSampleStatus_Failed) ? (ESampleStatus)Value : eSampleStatus_InValid) 

enum ETestStatus
{
	eTestStatus_Idle = -1,	// 无效
	eTestStatus_BeforeTest = 0,	// 未测
	eTestStatus_Block = 1,	// 阻塞   
	eTestStatus_Testing = 2,	// 测试中
	eTestStatus_Success = 3,	// 测试成功
	eTestStatus_Failed = 4,	// 测试失败
};
Q_DECLARE_METATYPE(ETestStatus);

#define  IsTestFinished(Value)	 (((Value) >= eTestStatus_Success && (Value) <= eTestStatus_Failed) ? true : false)
#define  IsTestSuccess(Value)	 (((Value) == eTestStatus_Success) ? true : false)
#define  IsTestBeforeTest(Value)	 (((Value) <= eTestStatus_Block) ? true : false)

// 手工条码和自动条码
enum EBarCodeSrcType
{
	eBarCode_Unknown = 0,
	eBarCode_Manual,
	eBarCode_Scan
};
#define Int2BarSrcType(Value) (((Value) >= eBarCode_Unknown && (Value) <= eBarCode_Scan) ? (EBarCodeSrcType)Value : eBarCode_Unknown) 

enum ESampleVialType  //样本管类型 : 采血管
{
	eSampleVials_Unkown = 0,	// 未知
	eSampleVials_BloodTube = 1,	// 采血管
	eSampleVials_StandardCup = 2,	// 标准杯
};
#define Int2SampleVialType(Value) (((Value) >= eSampleVials_Unkown && (Value) <= eSampleVials_StandardCup) ? (ESampleVialType)Value : eSampleVials_Unkown) 

// 盘类型
enum EPlateType
{
	ePlateType_NULL = -1,
	ePlateType_Sample = 0,		// 样本盘，专放置样本
	ePlateType_Reagent = 1,		// 试剂盘，专放置试剂
	ePlateType_Reaction = 2,		// 反应盘
	ePlateType_Mixed = 3			// 混合盘，放置样本和试剂
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
















enum EQcConcLevel		// 与界面设置一致
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
	eResultCalcType_Recent,		// 最后一次测试结果
	eResultCalcType_Average		// 所有测试的平均值
};

enum ETestOrderStatus
{
	eOrderStatus_NoneTested = 0,	// 全部未测试
	eOrderStatus_PartTested,		// 部分已测
	eOrderStatus_AllTested,			// 全部已测
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
	eClickRule_Not = 0,                 // 没有
	eClickRule_Precise,                 // 精确点击到点
	eClickRule_Round,                   // 以X轴坐标匹配曲线点
};

struct  SCurveParam
{
	QString sXName;                             // X轴标题
	QString sYName;                             // Y轴标题

	EClickRule eClickRule;                      // 点击类型：精确点击到曲线上的点显示、任意点以X轴匹配到曲线的点
	QFont   Plotfont;                           // 提示面板的字体
	bool    bIsDisplayLegend;                   // 是否显示提示面板
	QPen    CurveStylePen;                      // 曲线风格
	int     XTickerNum;                         // X轴刻度数
	int     YTickerNum;                         // Y轴刻度数

	int     XLabelRotation;                     // 刻度显示字符与X轴的夹角

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
	QVector<SCurvePoint> m_vecData;             // 曲线点数据
	QString m_sCTStr;                           // 曲线的描述(QDS1000是CT峰值，str格式：C：value，T：value)
	QPen m_CurveStylePen;                         // 曲线风格

	SCurvePlotData()
	{
		clear();
	}

	void clear() {
		m_vecData.clear();  m_sCTStr.clear(); m_CurveStylePen = QPen(QBrush(Qt::blue), 2, Qt::SolidLine);
	}
};



// 样本针的状态
enum ESamplePinStatus
{
	ePinStatus_UnKnown,		// 未知
	ePinStatus_Idle,		// 样本针空闲
	ePinStatus_Busy,		// 样本针忙 
};

// 样本杯的状态
enum ESampleCuvetteStatus
{
	eSampleCuvetteStatus_Unknown,   // 未知
	eSampleCuvetteStatus_Idle,
	eSampleCuvetteStatus_Testing,
};

// 反应杯的状态
enum ECuvetteStatus
{
	eCuvetteStatus_UnKnown,         // 未知
	eCuvetteStatus_Idle,
	eCuvetteStatus_Testing,

	//ichem将测试状态再分为以下
	eiChemCuvetteStatus_Idle = 100,	//空闲
	eiChemCuvetteStatus_AddR1,		//加试剂1
	eiChemCuvetteStatus_AddS,		//加样本
	eiChemCuvetteStatus_AddR2,		//加试剂2
	eiChemCuvetteStatus_AddR3,		//加试剂3
	eiChemCuvetteStatus_Dilu,		//稀释
	eiChemCuvetteStatus_Clear,		//反应杯清洗
	eiChemCuvetteStatus_Finish,		//清洗完成		
	eiChemCuvetteStatus_Dirty,		//脏杯
};



enum EDicFieldType
{
	eDic_Begin = 0,
	eDic_Precision,					// 精度
	eDic_SendOffice,				// 送检科室
	eDic_SendDoc,					// 送检医生
	eDic_TestDoc,					// 检验医生
	eDic_CheckDoc,					// 审核医生
	eDic_ResultUnit,				// 结果单位
	eDic_Diagnosis,					// 诊断
	eDic_ResultDesc,				// 结果描述
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


enum EReferRule	// 参考范围规则，定义参考范围的段数
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

// 盘圈，一般有内圈、中圈、外圈
enum EPlateCircleType
{
	ePlate_InnerCircle = 0,		// 内圈
	ePlate_MiddleCircle,		// 中圈
	ePlate_OutCircle,			// 外圈
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
	eQcType_RunTime,	// 实时质控
						//eQcType_Day,		// 天内质控
						eQcType_Days,		// 天间质控
};

//TODO: other defines
const int g_ciMaxSampleHoleNo = 60;		// 样本盘位置个数
const int g_ciMaxReagentHoleNo = 45;	// 试剂盘位置个数
const int g_ciMaxReactionHoleNo = 120;	// 反应盘位置个数

const int gc_iAbsorbVolumeForUltraClean = 48;
const int gc_iSoakTimeForUltraClean = 300;

enum ELisProtocolType
{
	eLisProtocolType_Unknown = 0,       // 未知
	eLisProtocolType_HL7,               // 标准HL7协议
	eLisProtocolType_ASTM,              // ASTM协议
	eLisProtocolType_Custom             // 自定义
};


//MC管理的串口设备定义接口
enum ESerialDevice
{
	eSerialDevice_MC = 0,	//主控板串口设备
	eSerialDevice_PP1,		//电源控制板设备
	eSerialDevice_ALL,
};

//蜂鸣器
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

//排空类型
enum EFlowDrainType
{
	eFlowDrain_CleanLiq = 0, //排空反应杯清洗液
	eFlowDrain_ReactionLiq,  //排空液路清洗液
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