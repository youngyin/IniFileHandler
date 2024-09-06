object FormMain: TFormMain
  Left = 0
  Top = 0
  Caption = 'FormMain'
  ClientHeight = 466
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object LblStatus: TLabel
    Left = 64
    Top = 184
    Width = 3
    Height = 15
  end
  object BtnSave: TButton
    Left = 489
    Top = 40
    Width = 75
    Height = 25
    Caption = 'SAVE'
    TabOrder = 0
  end
  object EdtFolderPath: TEdit
    Left = 64
    Top = 41
    Width = 338
    Height = 23
    TabOrder = 1
  end
  object BtnOpenFolderVcl: TButton
    Left = 408
    Top = 40
    Width = 75
    Height = 25
    Caption = 'OPEN(VCL)'
    TabOrder = 2
    OnClick = BtnOpenFolderVclClick
  end
  object BtnRead: TButton
    Left = 489
    Top = 153
    Width = 75
    Height = 25
    Caption = 'READ'
    TabOrder = 3
    OnClick = BtnReadClick
  end
  object MmResult: TMemo
    Left = 64
    Top = 216
    Width = 499
    Height = 209
    TabOrder = 4
  end
  object EdtFilePath: TEdit
    Left = 64
    Top = 155
    Width = 338
    Height = 23
    TabOrder = 5
  end
  object BtnOpenFile: TButton
    Left = 408
    Top = 153
    Width = 75
    Height = 25
    Caption = 'OPEN(VCL)'
    TabOrder = 6
    OnClick = BtnOpenFileClick
  end
end
