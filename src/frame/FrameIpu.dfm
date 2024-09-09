object FrameIpuNet: TFrameIpuNet
  Left = 0
  Top = 0
  Width = 800
  Height = 400
  TabOrder = 0
  object m_gbConfig: TGroupBox
    Left = 24
    Top = 24
    Width = 425
    Height = 121
    Caption = '[CONFIG]'
    TabOrder = 0
    object m_gpConfig: TGridPanel
      AlignWithMargins = True
      Left = 12
      Top = 27
      Width = 401
      Height = 82
      Margins.Left = 10
      Margins.Top = 10
      Margins.Right = 10
      Margins.Bottom = 10
      Align = alClient
      ColumnCollection = <
        item
          Value = 28.571428571428570000
        end
        item
          Value = 71.428571428571430000
        end>
      ControlCollection = <
        item
          Column = 0
          Control = m_lblKey1
          Row = 0
        end
        item
          Column = 1
          Control = m_edtDefaultSlot
          Row = 0
        end
        item
          Column = 0
          Control = m_lblKey2
          Row = 1
        end
        item
          Column = 1
          Control = m_edtLastset
          Row = 1
        end
        item
          Column = 0
          Control = m_lblKey3
          Row = 2
        end
        item
          Column = 1
          Control = m_edtLastSlot
          Row = 2
        end>
      RowCollection = <
        item
          Value = 33.333333333333340000
        end
        item
          Value = 33.333333333333340000
        end
        item
          Value = 33.333333333333340000
        end>
      ShowCaption = False
      TabOrder = 0
      ExplicitLeft = 96
      ExplicitTop = 58
      ExplicitWidth = 185
      ExplicitHeight = 41
      object m_lblKey1: TLabel
        Left = 1
        Top = 1
        Width = 77
        Height = 27
        Align = alLeft
        Caption = 'DEFAULT_SLOT'
        Layout = tlCenter
        ExplicitLeft = 14
        ExplicitTop = 2
        ExplicitHeight = 15
      end
      object m_edtDefaultSlot: TEdit
        AlignWithMargins = True
        Left = 118
        Top = 4
        Width = 279
        Height = 21
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 64
        ExplicitTop = 1
        ExplicitWidth = 121
        ExplicitHeight = 23
      end
      object m_lblKey2: TLabel
        Left = 1
        Top = 28
        Width = 44
        Height = 26
        Align = alLeft
        Caption = 'LASTSET'
        Layout = tlCenter
        ExplicitLeft = 14
        ExplicitTop = 22
        ExplicitHeight = 15
      end
      object m_edtLastset: TEdit
        AlignWithMargins = True
        Left = 118
        Top = 31
        Width = 279
        Height = 20
        Align = alClient
        TabOrder = 1
        ExplicitLeft = 204
        ExplicitWidth = 193
        ExplicitHeight = 23
      end
      object m_lblKey3: TLabel
        Left = 1
        Top = 54
        Width = 52
        Height = 27
        Align = alLeft
        Caption = 'LASTSLOT'
        Layout = tlCenter
        ExplicitLeft = 68
        ExplicitTop = 72
        ExplicitHeight = 15
      end
      object m_edtLastSlot: TEdit
        AlignWithMargins = True
        Left = 118
        Top = 57
        Width = 279
        Height = 21
        Align = alClient
        TabOrder = 2
        ExplicitLeft = 240
        ExplicitTop = 69
        ExplicitWidth = 121
        ExplicitHeight = 23
      end
    end
  end
  object m_gbSlotA: TGroupBox
    Left = 24
    Top = 159
    Width = 425
    Height = 210
    Caption = '[SLOT_A]'
    TabOrder = 1
    object m_gpSlotA: TGridPanel
      AlignWithMargins = True
      Left = 12
      Top = 27
      Width = 401
      Height = 171
      Margins.Left = 10
      Margins.Top = 10
      Margins.Right = 10
      Margins.Bottom = 10
      Align = alClient
      BiDiMode = bdLeftToRight
      Caption = '='
      ColumnCollection = <
        item
          Value = 23.419203747072600000
        end
        item
          Value = 58.548009367681500000
        end
        item
          Value = 18.032786885245900000
        end>
      ControlCollection = <
        item
          Column = 0
          Control = m_lblKey4
          Row = 0
        end
        item
          Column = 1
          Control = m_edtInterfaceIn
          Row = 0
        end
        item
          Column = 0
          Control = m_lblKey5
          Row = 1
        end
        item
          Column = 1
          Control = m_edtIpIn
          Row = 1
        end
        item
          Column = 0
          Control = m_lblKey6
          Row = 2
        end
        item
          Column = 1
          Control = m_edtInterfaceOut
          Row = 2
        end
        item
          Column = 0
          Control = m_lblKey7
          Row = 3
        end
        item
          Column = 1
          Control = m_edtIpOut
          Row = 3
        end
        item
          Column = 0
          Control = m_lblKey8
          Row = 4
        end
        item
          Column = 1
          Control = m_edtInterfaceCam1
          Row = 4
        end
        item
          Column = 0
          Control = m_lblKey9
          Row = 5
        end
        item
          Column = 1
          Control = m_edtIpCam1
          Row = 5
        end
        item
          Column = 2
          Control = m_BtnApply
          Row = 1
        end>
      Ctl3D = False
      ParentBiDiMode = False
      ParentCtl3D = False
      ParentShowHint = False
      RowCollection = <
        item
          Value = 16.666666666666670000
        end
        item
          Value = 16.666666666666670000
        end
        item
          Value = 16.666666666666670000
        end
        item
          Value = 16.666666666666670000
        end
        item
          Value = 16.666666666666670000
        end
        item
          Value = 16.666666666666650000
        end>
      ShowCaption = False
      ShowHint = False
      TabOrder = 0
      ExplicitLeft = 24
      ExplicitTop = 16
      ExplicitWidth = 386
      ExplicitHeight = 185
      object m_lblKey4: TLabel
        Left = 1
        Top = 1
        Width = 75
        Height = 28
        Align = alLeft
        Anchors = [akLeft]
        BiDiMode = bdRightToLeft
        Caption = 'INTERFACE_IN'
        ParentBiDiMode = False
        Layout = tlCenter
        ExplicitLeft = -71
        ExplicitHeight = 15
      end
      object m_edtInterfaceIn: TEdit
        AlignWithMargins = True
        Left = 97
        Top = 4
        Width = 228
        Height = 22
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 196
        ExplicitWidth = 186
        ExplicitHeight = 21
      end
      object m_lblKey5: TLabel
        Left = 1
        Top = 29
        Width = 27
        Height = 28
        Align = alLeft
        Caption = 'IP_IN'
        Layout = tlCenter
        ExplicitLeft = 14
        ExplicitTop = 22
        ExplicitHeight = 15
      end
      object m_edtIpIn: TEdit
        AlignWithMargins = True
        Left = 97
        Top = 32
        Width = 228
        Height = 22
        Align = alClient
        TabOrder = 1
        ExplicitLeft = 196
        ExplicitTop = 35
        ExplicitWidth = 186
        ExplicitHeight = 21
      end
      object m_lblKey6: TLabel
        Left = 1
        Top = 57
        Width = 86
        Height = 29
        Align = alLeft
        Caption = 'INTERFACE_OUT'
        Layout = tlCenter
        ExplicitLeft = 54
        ExplicitTop = 65
        ExplicitHeight = 15
      end
      object m_edtInterfaceOut: TEdit
        AlignWithMargins = True
        Left = 97
        Top = 60
        Width = 228
        Height = 23
        Align = alClient
        TabOrder = 2
        ExplicitLeft = 196
        ExplicitTop = 65
        ExplicitWidth = 186
        ExplicitHeight = 21
      end
      object m_lblKey7: TLabel
        Left = 1
        Top = 86
        Width = 38
        Height = 28
        Align = alLeft
        Caption = 'IP_OUT'
        Layout = tlCenter
        ExplicitLeft = 14
        ExplicitTop = 75
        ExplicitHeight = 15
      end
      object m_edtIpOut: TEdit
        AlignWithMargins = True
        Left = 97
        Top = 89
        Width = 228
        Height = 22
        Align = alClient
        TabOrder = 3
        ExplicitLeft = 196
        ExplicitTop = 96
        ExplicitWidth = 186
        ExplicitHeight = 21
      end
      object m_lblKey8: TLabel
        Left = 1
        Top = 114
        Width = 96
        Height = 28
        Align = alLeft
        Caption = 'INTERFACE_CAM1'
        Layout = tlCenter
        ExplicitTop = 107
        ExplicitHeight = 15
      end
      object m_edtInterfaceCam1: TEdit
        AlignWithMargins = True
        Left = 97
        Top = 117
        Width = 228
        Height = 22
        Align = alClient
        TabOrder = 4
        ExplicitLeft = 196
        ExplicitTop = 126
        ExplicitWidth = 186
        ExplicitHeight = 21
      end
      object m_lblKey9: TLabel
        Left = 1
        Top = 142
        Width = 48
        Height = 28
        Align = alLeft
        Caption = 'IP_CAM1'
        Layout = tlCenter
        ExplicitTop = 134
        ExplicitHeight = 15
      end
      object m_edtIpCam1: TEdit
        AlignWithMargins = True
        Left = 97
        Top = 145
        Width = 228
        Height = 22
        Align = alClient
        TabOrder = 5
        ExplicitLeft = 196
        ExplicitTop = 157
        ExplicitWidth = 186
        ExplicitHeight = 21
      end
      object m_BtnApply: TButton
        AlignWithMargins = True
        Left = 331
        Top = 32
        Width = 66
        Height = 22
        Align = alClient
        Caption = #48320#44221
        TabOrder = 6
        ExplicitLeft = 326
        ExplicitTop = 2
        ExplicitWidth = 75
        ExplicitHeight = 25
      end
    end
  end
end
