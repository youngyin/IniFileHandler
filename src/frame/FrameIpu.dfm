object FrameIpuNet: TFrameIpuNet
  Left = 0
  Top = 0
  Width = 991
  Height = 648
  TabOrder = 0
  object m_gbConfig: TGroupBox
    Left = 24
    Top = 48
    Width = 506
    Height = 121
    Caption = '[CONFIG]'
    TabOrder = 0
    object m_edtDefaultSlot: TLabeledEdit
      Left = 157
      Top = 23
      Width = 300
      Height = 23
      EditLabel.Width = 77
      EditLabel.Height = 23
      EditLabel.Caption = 'DEFAULT_SLOT'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 0
      Text = ''
    end
    object m_edtLastset: TLabeledEdit
      Left = 157
      Top = 52
      Width = 300
      Height = 23
      EditLabel.Width = 44
      EditLabel.Height = 23
      EditLabel.Caption = 'LASTSET'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 1
      Text = ''
    end
    object m_edtLastSlot: TLabeledEdit
      Left = 157
      Top = 81
      Width = 300
      Height = 23
      EditLabel.Width = 52
      EditLabel.Height = 23
      EditLabel.Caption = 'LASTSLOT'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 2
      Text = ''
    end
  end
  object m_gbSlotA: TGroupBox
    Left = 24
    Top = 175
    Width = 506
    Height = 210
    Caption = '[SLOT_A]'
    TabOrder = 1
    object m_edtInterfaceIn: TLabeledEdit
      Left = 157
      Top = 27
      Width = 300
      Height = 23
      EditLabel.Width = 75
      EditLabel.Height = 23
      EditLabel.Caption = 'INTERFACE_IN'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 0
      Text = ''
    end
    object m_edtIpIn: TLabeledEdit
      Left = 157
      Top = 56
      Width = 300
      Height = 23
      EditLabel.Width = 27
      EditLabel.Height = 23
      EditLabel.Caption = 'PI_IN'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 1
      Text = ''
    end
    object m_edtInterfaceOut: TLabeledEdit
      Left = 157
      Top = 85
      Width = 300
      Height = 23
      EditLabel.Width = 86
      EditLabel.Height = 23
      EditLabel.Caption = 'INTERFACE_OUT'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 2
      Text = ''
    end
    object m_edtIpOut: TLabeledEdit
      Left = 157
      Top = 114
      Width = 300
      Height = 23
      EditLabel.Width = 38
      EditLabel.Height = 23
      EditLabel.Caption = 'IP_OUT'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 3
      Text = ''
    end
    object m_edtInterfaceCam1: TLabeledEdit
      Left = 157
      Top = 143
      Width = 300
      Height = 23
      EditLabel.Width = 96
      EditLabel.Height = 23
      EditLabel.Caption = 'INTERFACE_CAM1'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 4
      Text = ''
    end
    object m_edtIpCam1: TLabeledEdit
      Left = 157
      Top = 172
      Width = 300
      Height = 23
      EditLabel.Width = 48
      EditLabel.Height = 23
      EditLabel.Caption = 'IP_CAM1'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 5
      Text = ''
    end
  end
  object m_btnApply: TButton
    Left = 455
    Top = 17
    Width = 75
    Height = 25
    Caption = 'APPLY'
    TabOrder = 2
    OnClick = m_btnApplyClick
  end
  object btnFind: TButton
    Left = 293
    Top = 17
    Width = 75
    Height = 25
    Caption = 'FIND'
    TabOrder = 3
    OnClick = btnFindClick
  end
  object m_edtPath: TLabeledEdit
    Left = 87
    Top = 19
    Width = 200
    Height = 23
    Color = cl3DLight
    EditLabel.Width = 28
    EditLabel.Height = 23
    EditLabel.Caption = 'PATH'
    LabelPosition = lpLeft
    LabelSpacing = 10
    ReadOnly = True
    TabOrder = 4
    Text = 
      'C:\\Users\\youngyin\\Downloads\\handlerResource\\init\\Init\\IPU' +
      '_netconfig.ini'
  end
  object m_btnLoad: TButton
    Left = 374
    Top = 17
    Width = 75
    Height = 25
    Caption = 'LOAD'
    TabOrder = 5
    OnClick = m_btnLoadClick
  end
  object m_gbNetWorkInfo: TGroupBox
    Left = 24
    Top = 400
    Width = 506
    Height = 217
    Caption = '[CURRENT NETWORK INFO]'
    TabOrder = 6
    object m_edtNetWorkInfo1: TLabeledEdit
      Left = 157
      Top = 23
      Width = 300
      Height = 23
      EditLabel.Width = 87
      EditLabel.Height = 23
      EditLabel.Caption = 'ADAPTER NAME'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 0
      Text = ''
    end
    object m_edtNetWorkInfo2: TLabeledEdit
      Left = 157
      Top = 52
      Width = 300
      Height = 23
      EditLabel.Width = 72
      EditLabel.Height = 23
      EditLabel.Caption = 'DESCRIPTION'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 1
      Text = ''
    end
    object m_edtNetWorkInfo3: TLabeledEdit
      Left = 157
      Top = 81
      Width = 300
      Height = 23
      EditLabel.Width = 62
      EditLabel.Height = 23
      EditLabel.Caption = 'IP ADDRESS'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 2
      Text = ''
    end
    object m_edtNetWorkInfo5: TLabeledEdit
      Left = 157
      Top = 139
      Width = 300
      Height = 23
      EditLabel.Width = 42
      EditLabel.Height = 23
      EditLabel.Caption = 'IPMASK'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 3
      Text = ''
    end
    object m_edtNetWorkInfo6: TLabeledEdit
      Left = 157
      Top = 168
      Width = 300
      Height = 23
      EditLabel.Width = 71
      EditLabel.Height = 23
      EditLabel.Caption = 'DHCPSERVER'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 4
      Text = ''
    end
    object m_edtNetWorkInfo4: TLabeledEdit
      Left = 157
      Top = 110
      Width = 300
      Height = 23
      EditLabel.Width = 52
      EditLabel.Height = 23
      EditLabel.Caption = 'GATEWAY'
      LabelPosition = lpLeft
      LabelSpacing = 10
      TabOrder = 5
      Text = ''
    end
  end
end
