object FormTabView: TFormTabView
  Left = 0
  Top = 0
  AutoSize = True
  Caption = #49444#51221#54532#47196#44536#47016
  ClientHeight = 677
  ClientWidth = 1010
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
    Width = 1010
    Height = 677
    ActivePage = m_tabRemote
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 624
    ExplicitHeight = 441
    object m_tabRemote: TTabSheet
      Caption = 'ConfigSetting'
      ImageIndex = 2
      inline Frame_ConfigSetting: TFrame_ConfigSetting
        Left = -4
        Top = 3
        Width = 1078
        Height = 714
        Color = clSilver
        ParentBackground = False
        ParentColor = False
        TabOrder = 0
        ExplicitLeft = -4
        ExplicitTop = 3
        ExplicitWidth = 1078
        ExplicitHeight = 714
        inherited GroupBox6: TGroupBox
          inherited m_Label_OneIPUSelectExpaln: TLabel
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited GroupBox7: TGroupBox
            inherited m_EditImgServerPort: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_MaskEditImgServerIP: TMaskEdit
              StyleElements = [seFont, seClient, seBorder]
            end
          end
          inherited GroupBox8: TGroupBox
            inherited m_EditMCPort: TEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_MaskEditMCServerIP: TMaskEdit
              StyleElements = [seFont, seClient, seBorder]
            end
          end
          inherited m_EditOneIPU: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_EditAxisWeight: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_EditOpType: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_EditSystemType: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_EditComPort: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_EditComType: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_EditTriggerType: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_EditPosition: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_EditComBaudRate: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_cbAxisWeight: TComboBox
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_cbBaudRate: TComboBox
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_cbComType: TComboBox
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_cbOneipu: TComboBox
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_cbOpType: TComboBox
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_cbPort: TComboBox
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_cbPosition: TComboBox
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_cbSystemType: TComboBox
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_cbTriggerType: TComboBox
            StyleElements = [seFont, seClient, seBorder]
          end
        end
        inherited GroupBox1: TGroupBox
          inherited m_EditRemoteServerPort: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_MaskEditRemoteServerAddress: TMaskEdit
            StyleElements = [seFont, seClient, seBorder]
          end
        end
        inherited GroupBox3: TGroupBox
          inherited GroupBox4: TGroupBox
            inherited m_Label_InNetChgExplan: TLabel
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_In_MaskEdit_IPAddress: TMaskEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_In_MaskEdit_SubNetAddress: TMaskEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_In_MaskEdit_GateWayAddress: TMaskEdit
              StyleElements = [seFont, seClient, seBorder]
            end
          end
          inherited GroupBox5: TGroupBox
            inherited m_Label_ExNetChgExplan: TLabel
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_Ex_MaskEdit_IPAddress: TMaskEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_Ex_MaskEdit_SubNetAddress: TMaskEdit
              StyleElements = [seFont, seClient, seBorder]
            end
            inherited m_Ex_MaskEdit_GateWayAddress: TMaskEdit
              StyleElements = [seFont, seClient, seBorder]
            end
          end
          inherited m_btnIpuFileLoad: TButton
            Top = 162
            ExplicitTop = 162
          end
          inherited m_btnIpuFileSave: TButton
            Top = 205
            ExplicitTop = 205
          end
        end
        inherited GroupBox2: TGroupBox
          inherited m_EditFtpServerPort: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_EditFtpLoginID: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_EditFtpLoginPW: TEdit
            StyleElements = [seFont, seClient, seBorder]
          end
          inherited m_MaskEditFtpServerAddress: TMaskEdit
            StyleElements = [seFont, seClient, seBorder]
          end
        end
      end
    end
  end
end
