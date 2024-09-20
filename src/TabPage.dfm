object FormTabView: TFormTabView
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 698
  ClientWidth = 1003
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object m_pageControl: TPageControl
    Left = 0
    Top = 0
    Width = 1003
    Height = 698
    ActivePage = m_tabRemote
    Align = alClient
    TabOrder = 0
    object m_tabIpu: TTabSheet
      Caption = 'IPU'
      ImageIndex = 1
      inline Frame_IpuNet: TFrame_IpuNet
        Left = 0
        Top = 0
        Width = 995
        Height = 668
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 995
        ExplicitHeight = 668
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
        inherited Memo1: TMemo
          StyleElements = [seFont, seClient, seBorder]
        end
        inherited Memo2: TMemo
          StyleElements = [seFont, seClient, seBorder]
        end
      end
    end
    object m_tabRemote: TTabSheet
      Caption = 'REMOTE'
      ImageIndex = 2
      inline Frame_ConfigSetting: TFrame_ConfigSetting
        Left = -4
        Top = 3
        Width = 1078
        Height = 714
        TabOrder = 0
        ExplicitLeft = -4
        ExplicitTop = 3
        ExplicitWidth = 1078
        ExplicitHeight = 714
        inherited GroupBox6: TGroupBox
          inherited GroupBox7: TGroupBox
            inherited Edit7: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited Edit8: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
          end
          inherited GroupBox8: TGroupBox
            inherited Edit9: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited Edit10: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
          end
          inherited Edit17: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited Edit18: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited Edit19: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited Edit20: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited Edit21: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited Edit22: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited Edit23: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited Edit24: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited Edit25: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
        end
        inherited GroupBox1: TGroupBox
          inherited Edit11: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited Edit12: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
        end
        inherited GroupBox3: TGroupBox
          inherited GroupBox4: TGroupBox
            inherited m_In_GateWayAddress: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_In_SubNetAddress: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_In_IPAddress: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
          end
          inherited GroupBox5: TGroupBox
            inherited m_Ex_IPAddress: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_Ex_SubNetAddress: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_Ex_GateWayAddress: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
          end
          inherited m_btnIpuFileLoad: TButton
            Top = 182
            ExplicitTop = 182
          end
          inherited m_btnIpuFileSave: TButton
            Top = 225
            ExplicitTop = 225
          end
        end
        inherited GroupBox2: TGroupBox
          inherited Edit13: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited Edit14: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited Edit15: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited Edit16: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
        end
      end
    end
  end
end
