object Frame_ConfigSetting: TFrame_ConfigSetting
  Left = 0
  Top = 0
  Width = 1009
  Height = 654
  Color = clSilver
  ParentBackground = False
  ParentColor = False
  TabOrder = 0
  object GroupBox6: TGroupBox
    Left = 16
    Top = 264
    Width = 740
    Height = 371
    Caption = #52264#47196#49444#51221
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object m_Label_OneIPUSelectExpaln: TLabel
      Left = 27
      Top = 74
      Width = 146
      Height = 23
      Caption = #54869#51221#50689#49345' '#49440#53469' '#49444#47749
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clDodgerblue
      Font.Height = -17
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold, fsUnderline]
      ParentFont = False
    end
    object GroupBox7: TGroupBox
      Left = 10
      Top = 232
      Width = 295
      Height = 121
      Caption = #51116#51064#49885' '#49436#48260
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object StaticText7: TStaticText
        Left = 54
        Top = 32
        Width = 20
        Height = 32
        Caption = 'IP'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object m_EditImgServerPort: TEdit
        Left = 142
        Top = 71
        Width = 139
        Height = 36
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnKeyPress = m_EditImgServerPortKeyPress
      end
      object StaticText8: TStaticText
        Left = 38
        Top = 74
        Width = 52
        Height = 32
        Caption = 'PORT'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object m_MaskEditImgServerIP: TMaskEdit
        Left = 141
        Top = 31
        Width = 140
        Height = 33
        TabOrder = 3
        Text = ''
      end
    end
    object GroupBox8: TGroupBox
      Left = 329
      Top = 232
      Width = 287
      Height = 121
      Caption = #51452#51228#50612#44592' '#49436#48260
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object StaticText9: TStaticText
        Left = 62
        Top = 32
        Width = 20
        Height = 32
        Caption = 'IP'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object StaticText10: TStaticText
        Left = 46
        Top = 73
        Width = 52
        Height = 32
        Caption = 'PORT'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object m_EditMCPort: TEdit
        Left = 137
        Top = 71
        Width = 139
        Height = 36
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        OnKeyPress = m_EditMCPortKeyPress
      end
      object m_MaskEditMCServerIP: TMaskEdit
        Left = 137
        Top = 32
        Width = 138
        Height = 33
        TabOrder = 3
        Text = ''
      end
    end
    object StaticText17: TStaticText
      Left = 11
      Top = 34
      Width = 84
      Height = 32
      Caption = #54869#51221#50689#49345
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object m_EditOneIPU: TEdit
      Left = 317
      Top = 30
      Width = 65
      Height = 36
      TabOrder = 3
    end
    object StaticText18: TStaticText
      Left = 11
      Top = 103
      Width = 84
      Height = 32
      Caption = #52629#51473#52264#47196
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
    object m_EditAxisWeight: TEdit
      Left = 317
      Top = 98
      Width = 65
      Height = 36
      TabOrder = 5
    end
    object StaticText19: TStaticText
      Left = 11
      Top = 146
      Width = 142
      Height = 29
      Caption = #51064#53552#54168#51060#49828' '#49444#51221
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
    end
    object m_EditOpType: TEdit
      Left = 317
      Top = 140
      Width = 65
      Height = 36
      TabOrder = 7
    end
    object StaticText20: TStaticText
      Left = 11
      Top = 188
      Width = 84
      Height = 32
      Caption = #52264#47196#53440#51077
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
    end
    object m_EditSystemType: TEdit
      Left = 317
      Top = 185
      Width = 65
      Height = 35
      TabOrder = 9
    end
    object m_EditComPort: TEdit
      Left = 652
      Top = 146
      Width = 72
      Height = 36
      TabOrder = 10
    end
    object StaticText21: TStaticText
      Left = 404
      Top = 142
      Width = 44
      Height = 32
      Caption = #54252#53944
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 11
    end
    object m_EditComType: TEdit
      Left = 652
      Top = 104
      Width = 72
      Height = 36
      TabOrder = 12
    end
    object StaticText22: TStaticText
      Left = 404
      Top = 104
      Width = 84
      Height = 32
      Caption = #53685#49888#48169#49885
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 13
    end
    object m_EditTriggerType: TEdit
      Left = 652
      Top = 62
      Width = 72
      Height = 36
      TabOrder = 14
    end
    object StaticText23: TStaticText
      Left = 404
      Top = 62
      Width = 44
      Height = 32
      Caption = #44160#51648
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 15
    end
    object m_EditPosition: TEdit
      Left = 652
      Top = 20
      Width = 72
      Height = 36
      TabOrder = 16
    end
    object StaticText24: TStaticText
      Left = 404
      Top = 20
      Width = 72
      Height = 32
      Caption = #51204'/'#54980#47732
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 17
    end
    object StaticText25: TStaticText
      Left = 404
      Top = 179
      Width = 92
      Height = 32
      Caption = 'Baud Rate'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 18
    end
    object m_EditComBaudRate: TEdit
      Left = 652
      Top = 188
      Width = 72
      Height = 36
      TabOrder = 19
    end
    object m_btnLaneFileLoad: TButton
      Left = 622
      Top = 256
      Width = 108
      Height = 42
      Caption = #48520#47084#50724#44592
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 20
      OnClick = m_btnLaneFileLoadClick
    end
    object m_btnLaneFileSave: TButton
      Left = 622
      Top = 304
      Width = 108
      Height = 41
      Caption = #51200#51109#54616#44592
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 21
      OnClick = m_btnLaneFileSaveClick
    end
    object m_cbAxisWeight: TComboBox
      Left = 182
      Top = 98
      Width = 129
      Height = 36
      TabOrder = 22
    end
    object m_cbBaudRate: TComboBox
      Left = 501
      Top = 188
      Width = 145
      Height = 36
      TabOrder = 23
    end
    object m_cbComType: TComboBox
      Left = 501
      Top = 104
      Width = 145
      Height = 36
      TabOrder = 24
    end
    object m_cbOneipu: TComboBox
      Left = 182
      Top = 30
      Width = 129
      Height = 36
      TabOrder = 25
      OnChange = m_cbOneipuChange
    end
    object m_cbOpType: TComboBox
      Left = 159
      Top = 143
      Width = 152
      Height = 33
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 26
      OnChange = m_cbOpTypeChange
    end
    object m_cbPort: TComboBox
      Left = 501
      Top = 146
      Width = 145
      Height = 36
      TabOrder = 27
    end
    object m_cbPosition: TComboBox
      Left = 501
      Top = 20
      Width = 145
      Height = 36
      TabOrder = 28
    end
    object m_cbSystemType: TComboBox
      Left = 182
      Top = 185
      Width = 129
      Height = 36
      TabOrder = 29
    end
    object m_cbTriggerType: TComboBox
      Left = 501
      Top = 62
      Width = 145
      Height = 36
      TabOrder = 30
    end
  end
  object GroupBox1: TGroupBox
    Left = 762
    Top = 288
    Width = 235
    Height = 185
    Caption = #44288#51228#50896#44201' '#49444#51221
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object StaticText11: TStaticText
      Left = 25
      Top = 40
      Width = 20
      Height = 32
      Caption = 'IP'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object StaticText12: TStaticText
      Left = 11
      Top = 86
      Width = 52
      Height = 32
      Caption = 'PORT'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object m_EditRemoteServerPort: TEdit
      Left = 69
      Top = 86
      Width = 148
      Height = 36
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnKeyPress = m_EditRemoteServerPortKeyPress
    end
    object m_btnRemoteFiledLoad: TButton
      Left = 11
      Top = 135
      Width = 95
      Height = 40
      Caption = #48520#47084#50724#44592
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = m_btnRemoteFiledLoadClick
    end
    object m_btnRemoteFiledSave: TButton
      Left = 125
      Top = 135
      Width = 92
      Height = 40
      Caption = #51200#51109#54616#44592
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = m_btnRemoteFiledSaveClick
    end
    object m_MaskEditRemoteServerAddress: TMaskEdit
      Left = 69
      Top = 44
      Width = 148
      Height = 33
      TabOrder = 5
      Text = ''
    end
  end
  object GroupBox3: TGroupBox
    Left = 16
    Top = 8
    Width = 740
    Height = 257
    Caption = #51060#45908#45367' '#49444#51221
    Color = clSilver
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentBackground = False
    ParentColor = False
    ParentFont = False
    TabOrder = 2
    object GroupBox4: TGroupBox
      Left = 16
      Top = 35
      Width = 289
      Height = 206
      Caption = #45236#48512#47581
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object StaticText1: TStaticText
        Left = 48
        Top = 48
        Width = 20
        Height = 32
        Caption = 'IP'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object StaticText2: TStaticText
        Left = 31
        Top = 95
        Width = 64
        Height = 32
        Caption = #49436#48652#45367
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object StaticText3: TStaticText
        Left = 16
        Top = 142
        Width = 104
        Height = 32
        Caption = #44172#51060#53944#50920#51060
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object m_In_MaskEdit_IPAddress: TMaskEdit
        Left = 135
        Top = 48
        Width = 151
        Height = 33
        TabOrder = 3
        Text = ''
      end
      object m_In_MaskEdit_SubNetAddress: TMaskEdit
        Left = 135
        Top = 95
        Width = 151
        Height = 33
        TabOrder = 4
        Text = ''
      end
      object m_In_MaskEdit_GateWayAddress: TMaskEdit
        Left = 135
        Top = 142
        Width = 151
        Height = 33
        TabOrder = 5
        Text = ''
      end
    end
    object GroupBox5: TGroupBox
      Left = 329
      Top = 35
      Width = 287
      Height = 206
      Caption = #50808#48512#47581
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object StaticText4: TStaticText
        Left = 48
        Top = 50
        Width = 20
        Height = 32
        Caption = 'IP'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object StaticText5: TStaticText
        Left = 32
        Top = 96
        Width = 64
        Height = 32
        Caption = #49436#48652#45367
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object StaticText6: TStaticText
        Left = 16
        Top = 142
        Width = 104
        Height = 32
        Caption = #44172#51060#53944#50920#51060
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object m_Ex_MaskEdit_IPAddress: TMaskEdit
        Left = 126
        Top = 50
        Width = 151
        Height = 33
        TabOrder = 3
        Text = ''
      end
      object m_Ex_MaskEdit_SubNetAddress: TMaskEdit
        Left = 126
        Top = 96
        Width = 151
        Height = 33
        TabOrder = 4
        Text = ''
      end
      object m_Ex_MaskEdit_GateWayAddress: TMaskEdit
        Left = 126
        Top = 142
        Width = 151
        Height = 33
        TabOrder = 5
        Text = ''
      end
    end
    object m_btnIpuFileLoad: TButton
      Left = 622
      Top = 157
      Width = 108
      Height = 37
      Caption = #48520#47084#50724#44592
      TabOrder = 2
      OnClick = m_btnIpuFileLoadClick
    end
    object m_btnIpuFileSave: TButton
      Left = 622
      Top = 204
      Width = 108
      Height = 37
      Caption = #51200#51109#54616#44592
      TabOrder = 3
      OnClick = m_btnIpuFileSaveClick
    end
  end
  object GroupBox2: TGroupBox
    Left = 762
    Top = 8
    Width = 232
    Height = 274
    Caption = 'FTP '#49444#51221
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    object m_btnFtpFiledSave: TButton
      Left = 123
      Top = 215
      Width = 92
      Height = 42
      Caption = #51200#51109#54616#44592
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = m_btnFtpFiledSaveClick
    end
    object m_btnFtpFiledLoad: TButton
      Left = 9
      Top = 215
      Width = 96
      Height = 42
      Caption = #48520#47084#50724#44592
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = m_btnFtpFiledLoadClick
    end
    object StaticText13: TStaticText
      Left = 11
      Top = 81
      Width = 52
      Height = 32
      Caption = 'PORT'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object StaticText14: TStaticText
      Left = 25
      Top = 32
      Width = 20
      Height = 32
      Caption = 'IP'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object m_EditFtpServerPort: TEdit
      Left = 69
      Top = 77
      Width = 148
      Height = 36
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnKeyPress = m_EditFtpServerPortKeyPress
    end
    object StaticText15: TStaticText
      Left = 25
      Top = 125
      Width = 23
      Height = 32
      Caption = 'ID'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
    end
    object m_EditFtpLoginID: TEdit
      Left = 69
      Top = 121
      Width = 148
      Height = 36
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
    end
    object StaticText16: TStaticText
      Left = 18
      Top = 167
      Width = 34
      Height = 32
      Caption = 'PW'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
    end
    object m_EditFtpLoginPW: TEdit
      Left = 69
      Top = 167
      Width = 148
      Height = 36
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnKeyPress = m_EditFtpLoginPWKeyPress
    end
    object m_MaskEditFtpServerAddress: TMaskEdit
      Left = 69
      Top = 35
      Width = 148
      Height = 33
      TabOrder = 9
      Text = ''
    end
  end
end
