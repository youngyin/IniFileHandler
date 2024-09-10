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
            inherited m_lblKey1: TLabel
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_edtDefaultSlot: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_lblKey2: TLabel
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_edtLastset: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_lblKey3: TLabel
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_edtLastSlot: TEdit
              StyleElements = [seFont, seClient, seBorder]
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
            ExplicitLeft = 11
            ExplicitTop = 26
            ExplicitWidth = 403
            ExplicitHeight = 173
            inherited m_lblKey4: TLabel
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_edtInterfaceIn: TEdit
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 98
              ExplicitWidth = 229
            end
            inherited m_lblKey5: TLabel
              StyleElements = [seFont, seClient, seBorder]
              ExplicitTop = 30
            end
            inherited m_edtIpIn: TEdit
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 98
              ExplicitTop = 33
              ExplicitWidth = 229
            end
            inherited m_lblKey6: TLabel
              StyleElements = [seFont, seClient, seBorder]
              ExplicitTop = 58
            end
            inherited m_edtInterfaceOut: TEdit
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 98
              ExplicitTop = 61
              ExplicitWidth = 229
            end
            inherited m_lblKey7: TLabel
              StyleElements = [seFont, seClient, seBorder]
              ExplicitTop = 87
            end
            inherited m_edtIpOut: TEdit
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 98
              ExplicitTop = 90
              ExplicitWidth = 229
            end
            inherited m_lblKey8: TLabel
              StyleElements = [seFont, seClient, seBorder]
              ExplicitTop = 115
            end
            inherited m_edtInterfaceCam1: TEdit
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 98
              ExplicitTop = 118
              ExplicitWidth = 229
            end
            inherited m_lblKey9: TLabel
              StyleElements = [seFont, seClient, seBorder]
              ExplicitTop = 144
            end
            inherited m_edtIpCam1: TEdit
              StyleElements = [seFont, seClient, seBorder]
              ExplicitLeft = 98
              ExplicitTop = 147
              ExplicitWidth = 229
            end
            inherited m_BtnApply: TButton
              ExplicitLeft = 333
              ExplicitTop = 33
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
    object m_tabFtp: TTabSheet
      Caption = 'FTP'
      ImageIndex = 2
    end
    object m_tabLane: TTabSheet
      Caption = 'LANE'
      ImageIndex = 3
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
