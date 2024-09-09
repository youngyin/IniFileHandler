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
  Menu = m_mainMenu
  TextHeight = 15
  object m_pageControl: TPageControl
    Left = 0
    Top = 0
    Width = 624
    Height = 441
    ActivePage = m_tabIpu
    Align = alClient
    TabOrder = 0
    object m_tabIpu: TTabSheet
      Caption = 'IPU'
      ImageIndex = 1
      inline FrameIpuNet1: TFrameIpuNet
        Left = 0
        Top = 0
        Width = 616
        Height = 411
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 616
        ExplicitHeight = 411
        inherited m_gbConfig: TGroupBox
          inherited m_gpConfig: TGridPanel
            ControlCollection = <
              item
                Column = 0
                Control = FrameIpuNet1.m_lblKey1
                Row = 0
              end
              item
                Column = 1
                Control = FrameIpuNet1.m_edtDefaultSlot
                Row = 0
              end
              item
                Column = 0
                Control = FrameIpuNet1.m_lblKey2
                Row = 1
              end
              item
                Column = 1
                Control = FrameIpuNet1.m_edtLastset
                Row = 1
              end
              item
                Column = 0
                Control = FrameIpuNet1.m_lblKey3
                Row = 2
              end
              item
                Column = 1
                Control = FrameIpuNet1.m_edtLastSlot
                Row = 2
              end>
            StyleElements = [seFont, seClient, seBorder]
            ExplicitLeft = 12
            ExplicitTop = 27
            ExplicitWidth = 401
            ExplicitHeight = 82
            inherited m_lblKey1: TLabel
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 1
              ExplicitTop = 1
            end
            inherited m_edtDefaultSlot: TEdit
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 118
              ExplicitTop = 4
              ExplicitWidth = 279
            end
            inherited m_lblKey2: TLabel
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 1
              ExplicitTop = 28
            end
            inherited m_edtLastset: TEdit
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 118
              ExplicitWidth = 279
            end
            inherited m_lblKey3: TLabel
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 1
              ExplicitTop = 54
            end
            inherited m_edtLastSlot: TEdit
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 118
              ExplicitTop = 57
              ExplicitWidth = 279
            end
          end
        end
        inherited m_gbSlotA: TGroupBox
          ParentCustomHint = False
          Ctl3D = False
          ParentCtl3D = False
          inherited m_gpSlotA: TGridPanel
            Left = 11
            Top = 26
            Width = 403
            Height = 173
            ControlCollection = <
              item
                Column = 0
                Control = FrameIpuNet1.m_lblKey4
                Row = 0
              end
              item
                Column = 1
                Control = FrameIpuNet1.m_edtInterfaceIn
                Row = 0
              end
              item
                Column = 0
                Control = FrameIpuNet1.m_lblKey5
                Row = 1
              end
              item
                Column = 1
                Control = FrameIpuNet1.m_edtIpIn
                Row = 1
              end
              item
                Column = 0
                Control = FrameIpuNet1.m_lblKey6
                Row = 2
              end
              item
                Column = 1
                Control = FrameIpuNet1.m_edtInterfaceOut
                Row = 2
              end
              item
                Column = 0
                Control = FrameIpuNet1.m_lblKey7
                Row = 3
              end
              item
                Column = 1
                Control = FrameIpuNet1.m_edtIpOut
                Row = 3
              end
              item
                Column = 0
                Control = FrameIpuNet1.m_lblKey8
                Row = 4
              end
              item
                Column = 1
                Control = FrameIpuNet1.m_edtInterfaceCam1
                Row = 4
              end
              item
                Column = 0
                Control = FrameIpuNet1.m_lblKey9
                Row = 5
              end
              item
                Column = 1
                Control = FrameIpuNet1.m_edtIpCam1
                Row = 5
              end
              item
                Column = 2
                Control = FrameIpuNet1.m_BtnApply
                Row = 1
              end>
            StyleElements = [seFont, seClient, seBorder]
            ExplicitLeft = 12
            ExplicitTop = 27
            ExplicitWidth = 401
            ExplicitHeight = 171
            inherited m_lblKey4: TLabel
              Height = 29
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 1
            end
            inherited m_edtInterfaceIn: TEdit
              Left = 98
              Width = 229
              Height = 23
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 118
              ExplicitWidth = 279
            end
            inherited m_lblKey5: TLabel
              Top = 30
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 1
              ExplicitTop = 29
            end
            inherited m_edtIpIn: TEdit
              Left = 98
              Top = 33
              Width = 229
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 118
              ExplicitTop = 32
              ExplicitWidth = 279
            end
            inherited m_lblKey6: TLabel
              Top = 58
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 1
              ExplicitTop = 57
            end
            inherited m_edtInterfaceOut: TEdit
              Left = 98
              Top = 61
              Width = 229
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 118
              ExplicitTop = 60
              ExplicitWidth = 279
            end
            inherited m_lblKey7: TLabel
              Top = 87
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 1
              ExplicitTop = 86
            end
            inherited m_edtIpOut: TEdit
              Left = 98
              Top = 90
              Width = 229
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 118
              ExplicitTop = 89
              ExplicitWidth = 279
            end
            inherited m_lblKey8: TLabel
              Top = 115
              Height = 29
              StyleElements = [seFont, seClient, seBorder]
              ExplicitTop = 114
            end
            inherited m_edtInterfaceCam1: TEdit
              Left = 98
              Top = 118
              Width = 229
              Height = 23
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 118
              ExplicitTop = 117
              ExplicitWidth = 279
            end
            inherited m_lblKey9: TLabel
              Top = 144
              StyleElements = [seFont, seClient, seBorder]
              ExplicitTop = 142
            end
            inherited m_edtIpCam1: TEdit
              Left = 98
              Top = 147
              Width = 229
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 118
              ExplicitTop = 145
              ExplicitWidth = 279
            end
            inherited m_BtnApply: TButton
              Left = 333
              Top = 33
              ExplicitLeft = 331
              ExplicitTop = 32
              ExplicitWidth = 66
              ExplicitHeight = 22
            end
          end
        end
      end
    end
    object m_tabRemote: TTabSheet
      Caption = 'REMOTE'
      ImageIndex = 2
      inline m_frameForRemote: TFrameForRemote
        Left = -24
        Top = -69
        Width = 640
        Height = 480
        TabOrder = 0
        ExplicitLeft = -24
        ExplicitTop = -69
      end
    end
  end
  object m_mainMenu: TMainMenu
    Left = 576
    Top = 384
    object Setting1: TMenuItem
      Caption = 'Setting'
      object N1: TMenuItem
        Caption = 'Setting ...'
        OnClick = N1Click
      end
    end
  end
end
