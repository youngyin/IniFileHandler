object FormMain: TFormMain
  Left = 0
  Top = 0
  Caption = 'FormMain'
  ClientHeight = 599
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
end
