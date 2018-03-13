object ChildForm: TChildForm
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  ClientHeight = 471
  ClientWidth = 800
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl: TPageControl
    Left = 0
    Top = 0
    Width = 800
    Height = 471
    ActivePage = FunctionsTabSheet
    Align = alClient
    TabOrder = 0
    object FunctionsTabSheet: TTabSheet
      Caption = #1056#1080#1089'. F(x), P(x)'
      object EmoValueLabel: TLabel
        Left = 3
        Top = 354
        Width = 130
        Height = 26
        Align = alCustom
        AutoSize = False
        Caption = 'Emo ='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object EcoValueLabel: TLabel
        Left = 135
        Top = 354
        Width = 122
        Height = 26
        AutoSize = False
        Caption = 'Eco ='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object Graphic: TChart
        Left = 3
        Top = 0
        Width = 786
        Height = 353
        AllowPanning = pmNone
        BackWall.Pen.Visible = False
        BottomWall.Brush.Gradient.EndColor = clSilver
        BottomWall.Brush.Gradient.StartColor = clGray
        BottomWall.Brush.Gradient.Visible = True
        BottomWall.Pen.Color = clGray
        BottomWall.Size = 4
        Gradient.Colors = <
          item
            Color = clWhite
            Transparency = 100
          end
          item
            Color = clWhite
            Offset = 1.000000000000000000
          end>
        Gradient.Direction = gdFromTopLeft
        Gradient.EndColor = clWhite
        Gradient.Visible = True
        LeftWall.Brush.Gradient.EndColor = clSilver
        LeftWall.Brush.Gradient.StartColor = clGray
        LeftWall.Brush.Gradient.Visible = True
        LeftWall.Color = clWhite
        LeftWall.Pen.Color = clGray
        LeftWall.Size = 4
        Title.Text.Strings = (
          'TChart')
        BottomAxis.Grid.Color = 14540253
        BottomAxis.LabelsFormat.Font.Color = clGray
        BottomAxis.LabelsFormat.Font.Height = -9
        BottomAxis.LabelStyle = talValue
        Frame.Visible = False
        LeftAxis.Axis.Width = 0
        LeftAxis.Grid.Color = 14540253
        LeftAxis.LabelsFormat.Font.Color = clGray
        LeftAxis.LabelsFormat.Font.Height = -9
        LeftAxis.LabelStyle = talValue
        View3D = False
        Zoom.Animated = True
        BevelWidth = 2
        Color = clWhite
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          27
          15
          27)
        ColorPaletteIndex = 11
        object FSeries: TFastLineSeries
          Legend.Text = 'F(x)'
          LegendTitle = 'F(x)'
          SeriesColor = clRed
          Title = 'F(x)'
          LinePen.Color = clRed
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
          Data = {0000000000}
          Detail = {0000000000}
        end
        object PSeries: TLineSeries
          SeriesColor = clBlue
          Title = 'P(x)'
          Brush.BackColor = clDefault
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
          Data = {0000000000}
          Detail = {0000000000}
        end
      end
      object GraphicFigureSaveButton: TButton
        Left = 3
        Top = 386
        Width = 786
        Height = 50
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
    end
    object ExTabSheet: TTabSheet
      Caption = #1056#1080#1089'. E(x)'
      ImageIndex = 1
      object Chart1: TChart
        Left = 3
        Top = 8
        Width = 786
        Height = 376
        AllowPanning = pmNone
        BackWall.Pen.Visible = False
        BottomWall.Brush.Gradient.EndColor = clSilver
        BottomWall.Brush.Gradient.StartColor = clGray
        BottomWall.Brush.Gradient.Visible = True
        BottomWall.Pen.Color = clGray
        BottomWall.Size = 4
        Gradient.Colors = <
          item
            Color = clWhite
            Transparency = 100
          end
          item
            Color = clWhite
            Offset = 1.000000000000000000
          end>
        Gradient.Direction = gdFromTopLeft
        Gradient.EndColor = clWhite
        Gradient.Visible = True
        LeftWall.Brush.Gradient.EndColor = clSilver
        LeftWall.Brush.Gradient.StartColor = clGray
        LeftWall.Brush.Gradient.Visible = True
        LeftWall.Color = clWhite
        LeftWall.Pen.Color = clGray
        LeftWall.Size = 4
        Title.Text.Strings = (
          'TChart')
        BottomAxis.Grid.Color = 14540253
        BottomAxis.LabelsFormat.Font.Color = clGray
        BottomAxis.LabelsFormat.Font.Height = -9
        BottomAxis.LabelStyle = talValue
        Frame.Visible = False
        LeftAxis.Axis.Width = 0
        LeftAxis.Grid.Color = 14540253
        LeftAxis.LabelsFormat.Font.Color = clGray
        LeftAxis.LabelsFormat.Font.Height = -9
        LeftAxis.LabelStyle = talValue
        View3D = False
        Zoom.Animated = True
        BevelWidth = 2
        Color = clWhite
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          27
          15
          27)
        ColorPaletteIndex = 11
        object ESeries: TFastLineSeries
          Legend.Text = 'F(x)'
          LegendTitle = 'F(x)'
          SeriesColor = clRed
          Title = 'E(x)'
          LinePen.Color = clRed
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
          Data = {0000000000}
          Detail = {0000000000}
        end
      end
      object Button1: TButton
        Left = 3
        Top = 390
        Width = 786
        Height = 50
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
    end
    object ValueTabSheet: TTabSheet
      Caption = #1058#1072#1073#1083#1080#1094#1072' '#1079#1085#1072#1095#1077#1085#1080#1081
      ImageIndex = 2
      object ValueTableMemo: TMemo
        Left = 0
        Top = 0
        Width = 792
        Height = 384
        Align = alTop
        Lines.Strings = (
          
            '  x                  F(x)                  P(x)                 ' +
            ' E(x)')
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
        ExplicitWidth = 789
      end
      object ValueTableSaveButton: TButton
        Left = 0
        Top = 390
        Width = 789
        Height = 50
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
    end
    object CoeffTableSheet: TTabSheet
      Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1099
      ImageIndex = 3
      object CoeffTableSaveButton: TButton
        Left = 0
        Top = 390
        Width = 789
        Height = 50
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object CoeffTableMemo: TMemo
        Left = 0
        Top = 0
        Width = 792
        Height = 384
        Align = alTop
        Lines.Strings = (
          '  X                  Y')
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 1
      end
    end
  end
end
