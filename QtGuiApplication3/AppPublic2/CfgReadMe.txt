	Path=_T("/System/");
	mapDefineItems[Path + _T("SerialDeviceSetting")] = _T("1,38400,0,8,0,1");
	串口配置参数:串口号，波特率，校验位，数据位，停止位，异步打开
	
	mapDefineItems[Path + _T("DemoTime")] = _T("200");
	Demo模式下测试数据间时间间隔，单位毫秒
	
	mapDefineItems[Path + _T("ResultCalcType")] = _T("0");
	测试结果的计算类型，0表示使用最后一次测试结果，1表示所有测试的平均值
	
	mapDefineItems[Path + _T("ShutDownWindows")] = _T("0");
	是否关闭电脑的标记，0表示不关闭，1表示关闭
	
	mapDefineItems[Path + _T("Dev_Language")] = _T("iCRP_CHN");
	仪器类型和语言标记，iCRP_CHN表示CRP仪器中文设备
	仪器类型需要带型号，否则上位机无法识别仪器类型,如:
	iMagicM7/iMagicS7/iMagicV7/iMagicM5/iMagicM9/iCRP/ 
	iChem320/iChem330/iChem335/iChem340/iChem520/iChem530/iChem535/iChem540/iChem720/iChem730/iChem735/iChem740
	语言类型：CHN/ENG，CHN表示中文，ENG表示英文
	
	Path=_T("/UI/");
	mapDefineItems[Path + _T("MenuStytle")] = _T("0");
	主界面风格：0下拉菜单；1导航界面
	
	mapDefineItems[Path + _T("CalibUIType")] = _T("0");
	定标界面使能：0定标申请界面；1定标刷卡界面
	
	mapDefineItems[Path + _T("SampleLiquidType")] = _T("1");
	默认的样本类型：1血清；2全血；3预稀释
	
	mapDefineItems[Path + _T("DefaultPcv")] = _T("35.0");
	默认的PCV红细胞压积值
	
	mapDefineItems[Path + _T("AlarmShieldPara")] = _T("0");
	报警编号的屏蔽，支持多个报警信息的屏蔽，屏蔽的报警编号使用英文分号隔开，如IU0x01;IU0x02;
	IU0x01表示x轴校准失败(检测不到光耦)，IU0x02表示x轴运动前未完成校准/校准失败

	mapDefineItems[Path + _T("FilterRange")] = _T("30000");
	反应曲线AD数据屏蔽参数，早于此限的AD数据，显示时强制为0;
	
	mapDefineItems[Path + _T("IsAuthorizeShield")] = _T("0");
	高级维护权限认证功能是否屏蔽，0表示不屏蔽，1表示屏蔽
	
	mapDefineItems[Path + _T("DataExportType")] = _T("0");
	数据导出类型定义：0，实时AD值导出；1，结果参数信息导出；2，实时AD值+结果参数信息导出
	
	mapDefineItems[Path + _T("StandbyTime")] = _T("30"); 
	待机时间定义：30，待机时间默认为30分钟
	
	mapDefineItems[Path + _T("PreDiluFactor")] = _T("1");
	预稀释倍数
	
	Path=_T("/Device/");
	mapDefineItems[Path + _T("DesignatedCuvette")] = _T("0");
	指定使用的反应杯号，如使用1号反应杯则为1；使用1/2/3号反应杯则为1,2,3

	Path=_T("/RFID/");
	mapDefineItems[Path + _T("RFIDType")] = _T("0");
	RFID类型，0表示Rankinda类型，1表示YZ类型
	
	mapDefineItems[Path + _T("RFIDPort")] = _T("0");
	RFID模块默认的串口号
	
	Path=_T("/ThermalPrinter/");
	mapDefineItems[Path + _T("SerialSetting")] = _T("COM1:9600,N,8,1");
	ThermalPrinter打印机串口设备信息，串口参数：串口号，波特率，校验位，数据位，停止位
	
	mapDefineItems[Path + _T("IsUsed")] = _T("0");
	ThermalPrinter打印机当前是否被使用

	Path=_T("/SPRMDThermalPrinter/");
	mapDefineItems[Path + _T("SerialSetting")] = _T("1,19200,0,8,0,1");
	SPRMDThermalPrinter打印机串口设备信息，串口参数：串口号，波特率，校验位，数据位，停止位，串口同步异步标记（0同步，1异步）
	
	mapDefineItems[Path + _T("IsUsed")] = _T("0");
	SPRMDThermalPrinter打印机当前是否被使用
	
	mapDefineItems[Path + _T("IsAutoPrint")] = _T("0");
	SPRMDThermalPrinter打印机是否开启自动打印功能

	Path=_T("/RDEM32EmbeddedThermal/");
	mapDefineItems[Path + _T("SerialSetting")] = _T("1,9600,0,8,1,1");	
	RDEM32EmbeddedThermal打印机串口设备信息，串口参数：串口号，波特率，校验位，数据位，停止位，串口同步异步标记（0同步，1异步）
	
	mapDefineItems[Path + _T("IsUsed")] = _T("0");
	SPRMDThermalPrinter打印机当前是否被使用
	
	mapDefineItems[Path + _T("IsAutoPrint")] = _T("0");
	SPRMDThermalPrinter打印机是否开启自动打印功能

	Path=_T("/ExternalPrinter/");
	mapDefineItems[Path + _T("SerialSetting")] = _T("0");	
	ExternalPrinter打印机串口设备信息，串口参数：串口号，波特率，校验位，数据位，停止位，串口同步异步标记（0同步，1异步）
	
	mapDefineItems[Path + _T("IsUsed")] = _T("0");
	ExternalPrinter打印机当前是否被使用
	
	
	Path=_T("/SOFTWARE/");
	mapDefineItems[Path + _T("Disk")] = _T("500");
	软件所在盘（如C盘）剩余的空间最少为500M
	
	mapDefineItems[Path + _T("Memory")] = _T("1024");
	系统内存最少为1024M
	
	Path=_T("/Lis/");
	mapDefineItems[Path + _T("IsStartLIS")] = _T("0");									
	0 不启用Lis 2启用Lis
	
	mapDefineItems[Path + _T("IsAutoUpload")] = _T("0");
	0 不自动上传 2 自动上传
	
	mapDefineItems[Path + _T("LisOutputType")] = _T("2");
	1 串口，2 TCP/IP
	
	mapDefineItems[Path + _T("LisSerialParam")] = _T("5,9600,0,8,1,0,17,19");
	串口号，波特率，校验位，数据位，停止位,流控制，XON，XOFF
	
	mapDefineItems[Path + _T("LisInternet")] = _T("127.0.0.1,1001");
	IP, 端口号
	
	mapDefineItems[Path + _T("OutputSerialParam")] = _T("3,9600,0,8,1,1");	
	串口号，波特率，校验位，数据位，停止位，串口同步异步标记（0同步，1异步）
