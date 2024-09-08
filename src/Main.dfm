object FormMain: TFormMain
  Left = 0
  Top = 0
  Caption = 'FormMain'
  ClientHeight = 753
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object LblStatus: TLabel
    Left = 64
    Top = 120
    Width = 65
    Height = 15
    Caption = 'STATUS >>>'
    Transparent = True
  end
  object BtnSave: TButton
    Left = 489
    Top = 59
    Width = 75
    Height = 25
    Caption = 'SAVE'
    TabOrder = 0
    OnClick = btnSaveClick
  end
  object EdtFolderPath: TEdit
    Left = 64
    Top = 62
    Width = 338
    Height = 23
    TabOrder = 1
  end
  object BtnOpenFolderVcl: TButton
    Left = 408
    Top = 59
    Width = 75
    Height = 25
    Caption = 'OPEN(VCL)'
    TabOrder = 2
    OnClick = BtnOpenFolderVclClick
  end
  object BtnRead: TButton
    Left = 489
    Top = 90
    Width = 75
    Height = 25
    Caption = 'READ'
    TabOrder = 3
    OnClick = BtnReadClick
  end
  object MmResult: TMemo
    Left = 64
    Top = 144
    Width = 499
    Height = 186
    TabOrder = 4
  end
  object EdtFilePath: TEdit
    Left = 64
    Top = 91
    Width = 338
    Height = 23
    TabOrder = 5
  end
  object BtnOpenFile: TButton
    Left = 408
    Top = 90
    Width = 75
    Height = 25
    Caption = 'OPEN(VCL)'
    TabOrder = 6
    OnClick = BtnOpenFileClick
  end
  object SpinEditInterval: TSpinEdit
    Left = 64
    Top = 336
    Width = 121
    Height = 24
    EditorEnabled = False
    MaxLength = 3
    MaxValue = 999
    MinValue = 0
    TabOrder = 7
    Value = 0
  end
  object BtnStopMoveThread: TButton
    Left = 191
    Top = 336
    Width = 75
    Height = 25
    Caption = 'STOP'
    TabOrder = 8
    OnClick = BtnStopMoveThreadClick
  end
  object BtnResumeMoveThread: TButton
    Left = 272
    Top = 336
    Width = 75
    Height = 25
    Caption = 'START'
    TabOrder = 9
    OnClick = BtnResumeMoveThreadClick
  end
  object MmResultMove: TMemo
    Left = 65
    Top = 367
    Width = 499
    Height = 194
    TabOrder = 10
  end
  inline FrameForThread1: TFrameForThread
    Left = 64
    Top = 575
    Width = 499
    Height = 130
    Color = clWhite
    ParentBackground = False
    ParentColor = False
    TabOrder = 11
    ExplicitLeft = 64
    ExplicitTop = 575
    ExplicitWidth = 499
    ExplicitHeight = 130
    inherited GridPanel: TGridPanel
      Width = 499
      Height = 130
      ControlCollection = <
        item
          Column = 0
          Control = FrameForThread1.m_btnStart
          Row = 0
        end
        item
          Column = 1
          Control = FrameForThread1.m_btnStop
          Row = 0
        end
        item
          Column = 0
          Control = FrameForThread1.m_btnStatus
          Row = 1
        end
        item
          Column = 0
          Control = FrameForThread1.m_spinEditSec
          Row = 2
        end
        item
          Column = 1
          Control = FrameForThread1.Label3
          Row = 2
        end>
      StyleElements = [seFont, seClient, seBorder]
      ExplicitLeft = 48
      ExplicitTop = 0
      ExplicitWidth = 451
      ExplicitHeight = 105
      inherited m_btnStart: TButton
        Width = 242
        Height = 37
        ExplicitLeft = 4
        ExplicitTop = 4
        ExplicitWidth = 242
        ExplicitHeight = 58
      end
      inherited m_btnStop: TButton
        Left = 252
        Width = 243
        Height = 37
        ExplicitLeft = 252
        ExplicitTop = 4
        ExplicitWidth = 243
        ExplicitHeight = 58
      end
      inherited m_btnStatus: TButton
        Top = 47
        Width = 242
        Height = 36
        ExplicitLeft = 4
        ExplicitTop = 68
        ExplicitWidth = 242
        ExplicitHeight = 59
      end
      inherited m_spinEditSec: TSpinEdit
        Top = 89
        Width = 242
        Height = 37
        StyleElements = [seFont, seClient, seBorder]
        ExplicitLeft = 4
        ExplicitTop = 133
        ExplicitWidth = 242
        ExplicitHeight = 58
      end
      inherited Label3: TLabel
        Left = 252
        Top = 89
        Width = 243
        Height = 37
        Caption = '('#52488') '#45800#50948#47196' '#51077#47141
        StyleElements = [seFont, seClient, seBorder]
        ExplicitLeft = 252
        ExplicitTop = 68
        ExplicitWidth = 86
      end
    end
  end
end
