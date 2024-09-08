object FormTabView: TFormTabView
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 624
    Height = 441
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'TabSheet1'
      ImageIndex = 1
      inline FrameFirst1: TFrameFirst
        Left = 0
        Top = 0
        Width = 616
        Height = 411
        Align = alClient
        TabOrder = 0
        ExplicitLeft = -24
        ExplicitTop = -69
        ExplicitWidth = 616
        ExplicitHeight = 411
        inherited LblFirst: TLabel
          Left = 280
          Top = 200
          StyleElements = [seFont, seClient, seBorder]
          ExplicitLeft = 280
          ExplicitTop = 200
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'TabSheet2'
      ImageIndex = 2
      inline FrameSecond1: TFrameSecond
        Left = 0
        Top = 0
        Width = 616
        Height = 411
        Align = alClient
        TabOrder = 0
        ExplicitLeft = -24
        ExplicitTop = -69
        ExplicitWidth = 616
        ExplicitHeight = 411
        inherited LblSecond: TLabel
          Left = 272
          Top = 200
          StyleElements = [seFont, seClient, seBorder]
          ExplicitLeft = 272
          ExplicitTop = 200
        end
      end
    end
  end
end
