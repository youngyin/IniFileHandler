object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 466
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object btnSave: TButton
    Left = 64
    Top = 224
    Width = 75
    Height = 25
    Caption = 'SAVE'
    TabOrder = 0
    OnClick = btnSaveClick
  end
  object edtFilePath: TEdit
    Left = 64
    Top = 185
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object btnOpenFolderVcl: TButton
    Left = 208
    Top = 184
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 2
    OnClick = btnOpenFolderVclClick
  end
end
