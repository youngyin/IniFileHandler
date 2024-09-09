object FrameForLabelEdit: TFrameForLabelEdit
  Left = 0
  Top = 0
  Width = 640
  Height = 480
  TabOrder = 0
  object GridPanel1: TGridPanel
    Left = 0
    Top = 0
    Width = 640
    Height = 480
    Align = alClient
    ColumnCollection = <
      item
        Value = 50.000000000000000000
      end
      item
        Value = 50.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = m_lblName
        Row = 0
      end
      item
        Column = 1
        Control = m_edtValue
        Row = 0
      end>
    RowCollection = <
      item
        Value = 100.000000000000000000
      end>
    ShowCaption = False
    TabOrder = 0
    ExplicitLeft = 168
    ExplicitTop = 216
    ExplicitWidth = 185
    ExplicitHeight = 41
    DesignSize = (
      640
      480)
    object m_lblName: TLabel
      Left = 159
      Top = 232
      Width = 3
      Height = 15
      Anchors = []
      ExplicitLeft = 136
    end
    object m_edtValue: TEdit
      Left = 419
      Top = 228
      Width = 121
      Height = 23
      Anchors = []
      TabOrder = 0
      ExplicitLeft = 528
      ExplicitTop = 272
    end
  end
end
