object FormTabView: TFormTabView
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 631
  ClientWidth = 580
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
    Width = 580
    Height = 631
    ActivePage = m_tabIpu
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 1019
    ExplicitHeight = 441
    object m_tabIpu: TTabSheet
      Caption = 'IPU'
      ImageIndex = 1
      inline FrameIpuNet1: TFrameIpuNet
        Left = 0
        Top = 0
        Width = 572
        Height = 601
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 1011
        ExplicitHeight = 411
        inherited m_gbConfig: TGroupBox
          inherited m_edtDefaultSlot: TLabeledEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_edtLastset: TLabeledEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_edtLastSlot: TLabeledEdit
            StyleElements = [seFont, seClient, seBorder]
          end
        end
        inherited m_gbSlotA: TGroupBox
          ParentCustomHint = False
          Ctl3D = False
          ParentCtl3D = False
          inherited m_edtInterfaceIn: TLabeledEdit
            Height = 21
            EditLabel.Height = 21
            EditLabel.ExplicitHeight = 21
            StyleElements = [seFont, seClient, seBorder]
            ExplicitHeight = 21
          end
          inherited m_edtIpIn: TLabeledEdit
            Height = 21
            EditLabel.Height = 21
            EditLabel.ExplicitHeight = 21
            StyleElements = [seFont, seClient, seBorder]
            ExplicitHeight = 21
          end
          inherited m_edtInterfaceOut: TLabeledEdit
            Height = 21
            EditLabel.Height = 21
            EditLabel.ExplicitHeight = 21
            StyleElements = [seFont, seClient, seBorder]
            ExplicitHeight = 21
          end
          inherited m_edtIpOut: TLabeledEdit
            Height = 21
            EditLabel.Height = 21
            EditLabel.ExplicitHeight = 21
            StyleElements = [seFont, seClient, seBorder]
            ExplicitHeight = 21
          end
          inherited m_edtInterfaceCam1: TLabeledEdit
            Height = 21
            EditLabel.Height = 21
            EditLabel.ExplicitHeight = 21
            StyleElements = [seFont, seClient, seBorder]
            ExplicitHeight = 21
          end
          inherited m_edtIpCam1: TLabeledEdit
            Height = 21
            EditLabel.Height = 21
            EditLabel.ExplicitHeight = 21
            StyleElements = [seFont, seClient, seBorder]
            ExplicitHeight = 21
          end
        end
        inherited m_edtPath: TLabeledEdit
          StyleElements = [seFont, seClient, seBorder]
        end
        inherited m_gbNetWorkInfo: TGroupBox
          inherited m_edtNetWorkInfo1: TLabeledEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_edtNetWorkInfo2: TLabeledEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_edtNetWorkInfo3: TLabeledEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_edtNetWorkInfo5: TLabeledEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_edtNetWorkInfo6: TLabeledEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_edtNetWorkInfo4: TLabeledEdit
            StyleElements = [seFont, seClient, seBorder]
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
