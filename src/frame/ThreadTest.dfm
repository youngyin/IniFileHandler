object FrameForThread: TFrameForThread
  Left = 0
  Top = 0
  Width = 476
  Height = 307
  TabOrder = 0
  object GridPanel: TGridPanel
    Left = 0
    Top = 0
    Width = 476
    Height = 307
    ParentCustomHint = False
    Align = alClient
    Caption = 'GridPanel'
    ColumnCollection = <
      item
        Value = 50.000000000000000000
      end
      item
        Value = 50.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = m_btnStart
        Row = 0
      end
      item
        Column = 1
        Control = m_btnStop
        Row = 0
      end
      item
        Column = 0
        Control = m_btnStatus
        Row = 1
      end
      item
        Column = 0
        Control = m_spinEditSec
        Row = 2
      end
      item
        Column = 1
        Control = Label3
        Row = 2
      end>
    ParentShowHint = False
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
    ShowHint = False
    TabOrder = 0
    ExplicitLeft = 108
    ExplicitTop = 40
    ExplicitWidth = 255
    ExplicitHeight = 155
    object m_btnStart: TButton
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 231
      Height = 96
      Align = alClient
      Caption = 'START'
      TabOrder = 0
      OnClick = m_btnStartClick
      ExplicitLeft = 26
      ExplicitTop = 18
      ExplicitWidth = 75
      ExplicitHeight = 25
    end
    object m_btnStop: TButton
      AlignWithMargins = True
      Left = 241
      Top = 4
      Width = 231
      Height = 96
      Align = alClient
      Caption = 'STOP'
      TabOrder = 1
      OnClick = m_btnStopClick
      ExplicitLeft = 153
      ExplicitTop = 18
      ExplicitWidth = 75
      ExplicitHeight = 25
    end
    object m_btnStatus: TButton
      AlignWithMargins = True
      Left = 4
      Top = 106
      Width = 231
      Height = 95
      Align = alClient
      Caption = 'CHECK'
      TabOrder = 2
      OnClick = m_btnStatusClick
      ExplicitLeft = 26
      ExplicitTop = 78
      ExplicitWidth = 75
      ExplicitHeight = 25
    end
    object m_spinEditSec: TSpinEdit
      AlignWithMargins = True
      Left = 4
      Top = 207
      Width = 231
      Height = 96
      Align = alClient
      EditorEnabled = False
      MaxValue = 200
      MinValue = 0
      TabOrder = 3
      Value = 0
      ExplicitLeft = 59
      ExplicitTop = 141
      ExplicitWidth = 121
      ExplicitHeight = 24
    end
    object Label3: TLabel
      AlignWithMargins = True
      Left = 241
      Top = 207
      Width = 231
      Height = 96
      Align = alClient
      Alignment = taCenter
      BiDiMode = bdLeftToRight
      Caption = #52488
      ParentBiDiMode = False
      Layout = tlCenter
      ExplicitLeft = 324
      ExplicitTop = 145
      ExplicitWidth = 12
      ExplicitHeight = 15
    end
  end
end
