	Path=_T("/System/");
	mapDefineItems[Path + _T("SerialDeviceSetting")] = _T("1,38400,0,8,0,1");
	�������ò���:���ںţ������ʣ�У��λ������λ��ֹͣλ���첽��
	
	mapDefineItems[Path + _T("DemoTime")] = _T("200");
	Demoģʽ�²������ݼ�ʱ��������λ����
	
	mapDefineItems[Path + _T("ResultCalcType")] = _T("0");
	���Խ���ļ������ͣ�0��ʾʹ�����һ�β��Խ����1��ʾ���в��Ե�ƽ��ֵ
	
	mapDefineItems[Path + _T("ShutDownWindows")] = _T("0");
	�Ƿ�رյ��Եı�ǣ�0��ʾ���رգ�1��ʾ�ر�
	
	mapDefineItems[Path + _T("Dev_Language")] = _T("iCRP_CHN");
	�������ͺ����Ա�ǣ�iCRP_CHN��ʾCRP���������豸
	����������Ҫ���ͺţ�������λ���޷�ʶ����������,��:
	iMagicM7/iMagicS7/iMagicV7/iMagicM5/iMagicM9/iCRP/ 
	iChem320/iChem330/iChem335/iChem340/iChem520/iChem530/iChem535/iChem540/iChem720/iChem730/iChem735/iChem740
	�������ͣ�CHN/ENG��CHN��ʾ���ģ�ENG��ʾӢ��
	
	Path=_T("/UI/");
	mapDefineItems[Path + _T("MenuStytle")] = _T("0");
	��������0�����˵���1��������
	
	mapDefineItems[Path + _T("CalibUIType")] = _T("0");
	�������ʹ�ܣ�0����������棻1����ˢ������
	
	mapDefineItems[Path + _T("SampleLiquidType")] = _T("1");
	Ĭ�ϵ��������ͣ�1Ѫ�壻2ȫѪ��3Ԥϡ��
	
	mapDefineItems[Path + _T("DefaultPcv")] = _T("35.0");
	Ĭ�ϵ�PCV��ϸ��ѹ��ֵ
	
	mapDefineItems[Path + _T("AlarmShieldPara")] = _T("0");
	������ŵ����Σ�֧�ֶ��������Ϣ�����Σ����εı������ʹ��Ӣ�ķֺŸ�������IU0x01;IU0x02;
	IU0x01��ʾx��У׼ʧ��(��ⲻ������)��IU0x02��ʾx���˶�ǰδ���У׼/У׼ʧ��

	mapDefineItems[Path + _T("FilterRange")] = _T("30000");
	��Ӧ����AD�������β��������ڴ��޵�AD���ݣ���ʾʱǿ��Ϊ0;
	
	mapDefineItems[Path + _T("IsAuthorizeShield")] = _T("0");
	�߼�ά��Ȩ����֤�����Ƿ����Σ�0��ʾ�����Σ�1��ʾ����
	
	mapDefineItems[Path + _T("DataExportType")] = _T("0");
	���ݵ������Ͷ��壺0��ʵʱADֵ������1�����������Ϣ������2��ʵʱADֵ+���������Ϣ����
	
	mapDefineItems[Path + _T("StandbyTime")] = _T("30"); 
	����ʱ�䶨�壺30������ʱ��Ĭ��Ϊ30����
	
	mapDefineItems[Path + _T("PreDiluFactor")] = _T("1");
	Ԥϡ�ͱ���
	
	Path=_T("/Device/");
	mapDefineItems[Path + _T("DesignatedCuvette")] = _T("0");
	ָ��ʹ�õķ�Ӧ���ţ���ʹ��1�ŷ�Ӧ����Ϊ1��ʹ��1/2/3�ŷ�Ӧ����Ϊ1,2,3

	Path=_T("/RFID/");
	mapDefineItems[Path + _T("RFIDType")] = _T("0");
	RFID���ͣ�0��ʾRankinda���ͣ�1��ʾYZ����
	
	mapDefineItems[Path + _T("RFIDPort")] = _T("0");
	RFIDģ��Ĭ�ϵĴ��ں�
	
	Path=_T("/ThermalPrinter/");
	mapDefineItems[Path + _T("SerialSetting")] = _T("COM1:9600,N,8,1");
	ThermalPrinter��ӡ�������豸��Ϣ�����ڲ��������ںţ������ʣ�У��λ������λ��ֹͣλ
	
	mapDefineItems[Path + _T("IsUsed")] = _T("0");
	ThermalPrinter��ӡ����ǰ�Ƿ�ʹ��

	Path=_T("/SPRMDThermalPrinter/");
	mapDefineItems[Path + _T("SerialSetting")] = _T("1,19200,0,8,0,1");
	SPRMDThermalPrinter��ӡ�������豸��Ϣ�����ڲ��������ںţ������ʣ�У��λ������λ��ֹͣλ������ͬ���첽��ǣ�0ͬ����1�첽��
	
	mapDefineItems[Path + _T("IsUsed")] = _T("0");
	SPRMDThermalPrinter��ӡ����ǰ�Ƿ�ʹ��
	
	mapDefineItems[Path + _T("IsAutoPrint")] = _T("0");
	SPRMDThermalPrinter��ӡ���Ƿ����Զ���ӡ����

	Path=_T("/RDEM32EmbeddedThermal/");
	mapDefineItems[Path + _T("SerialSetting")] = _T("1,9600,0,8,1,1");	
	RDEM32EmbeddedThermal��ӡ�������豸��Ϣ�����ڲ��������ںţ������ʣ�У��λ������λ��ֹͣλ������ͬ���첽��ǣ�0ͬ����1�첽��
	
	mapDefineItems[Path + _T("IsUsed")] = _T("0");
	SPRMDThermalPrinter��ӡ����ǰ�Ƿ�ʹ��
	
	mapDefineItems[Path + _T("IsAutoPrint")] = _T("0");
	SPRMDThermalPrinter��ӡ���Ƿ����Զ���ӡ����

	Path=_T("/ExternalPrinter/");
	mapDefineItems[Path + _T("SerialSetting")] = _T("0");	
	ExternalPrinter��ӡ�������豸��Ϣ�����ڲ��������ںţ������ʣ�У��λ������λ��ֹͣλ������ͬ���첽��ǣ�0ͬ����1�첽��
	
	mapDefineItems[Path + _T("IsUsed")] = _T("0");
	ExternalPrinter��ӡ����ǰ�Ƿ�ʹ��
	
	
	Path=_T("/SOFTWARE/");
	mapDefineItems[Path + _T("Disk")] = _T("500");
	��������̣���C�̣�ʣ��Ŀռ�����Ϊ500M
	
	mapDefineItems[Path + _T("Memory")] = _T("1024");
	ϵͳ�ڴ�����Ϊ1024M
	
	Path=_T("/Lis/");
	mapDefineItems[Path + _T("IsStartLIS")] = _T("0");									
	0 ������Lis 2����Lis
	
	mapDefineItems[Path + _T("IsAutoUpload")] = _T("0");
	0 ���Զ��ϴ� 2 �Զ��ϴ�
	
	mapDefineItems[Path + _T("LisOutputType")] = _T("2");
	1 ���ڣ�2 TCP/IP
	
	mapDefineItems[Path + _T("LisSerialParam")] = _T("5,9600,0,8,1,0,17,19");
	���ںţ������ʣ�У��λ������λ��ֹͣλ,�����ƣ�XON��XOFF
	
	mapDefineItems[Path + _T("LisInternet")] = _T("127.0.0.1,1001");
	IP, �˿ں�
	
	mapDefineItems[Path + _T("OutputSerialParam")] = _T("3,9600,0,8,1,1");	
	���ںţ������ʣ�У��λ������λ��ֹͣλ������ͬ���첽��ǣ�0ͬ����1�첽��
