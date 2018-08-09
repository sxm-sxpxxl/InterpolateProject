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
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl: TPageControl
    Left = 0
    Top = 0
    Width = 800
    Height = 471
    ActivePage = ExTabSheet
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'GOST type B'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object FunctionsTabSheet: TTabSheet
      Caption = #1056#1080#1089'. F(x), P(x)'
      ExplicitTop = 24
      ExplicitHeight = 443
      object Graphic: TChart
        Left = 3
        Top = 0
        Width = 642
        Height = 394
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
        Title.Font.Color = clBlack
        Title.Font.Height = -16
        Title.Font.Name = 'GOST type B'
        Title.Font.Style = [fsBold]
        Title.Text.Strings = (
          #1043#1088#1072#1092#1080#1082#1080' '#1080#1089#1093#1086#1076#1085#1086#1081' '#1092#1091#1085#1082#1094#1080#1080' F(x) '#1080' '#1080#1085#1090#1077#1088#1087#1086#1083#1103#1094#1080#1086#1085#1085#1086#1075#1086' '#1087#1086#1083#1080#1085#1086#1084#1072' P(x)')
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
        Top = 400
        Width = 786
        Height = 36
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'GOST type B'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = GraphicFigureSaveButtonClick
      end
      object GroupBox1: TGroupBox
        Left = 648
        Top = 0
        Width = 141
        Height = 86
        Caption = #1055#1086#1075#1088#1077#1096#1085#1086#1089#1090#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'GOST type B'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        object emoLabel: TLabel
          Left = 3
          Top = 15
          Width = 50
          Height = 26
          Align = alCustom
          AutoSize = False
          Caption = 'E'#1084'o ='
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = 'GOST type A'
          Font.Style = []
          ParentFont = False
        end
        object EmoValueLabel: TLabel
          Left = 59
          Top = 16
          Width = 11
          Height = 28
          Align = alCustom
          Caption = '0'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = 'GOST type B'
          Font.Style = []
          ParentFont = False
        end
        object ecoLabel: TLabel
          Left = 3
          Top = 50
          Width = 50
          Height = 26
          AutoSize = False
          Caption = 'Eco ='
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = 'GOST type A'
          Font.Style = []
          ParentFont = False
        end
        object EcoValueLabel: TLabel
          Left = 59
          Top = 50
          Width = 11
          Height = 26
          Caption = '0'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = 'GOST type B'
          Font.Style = []
          ParentFont = False
        end
      end
    end
    object ExTabSheet: TTabSheet
      Caption = #1056#1080#1089'. E(x)'
      ImageIndex = 1
      ExplicitLeft = 108
      ExplicitTop = -88
      ExplicitHeight = 443
      object ErrorChart: TChart
        Left = 3
        Top = 0
        Width = 786
        Height = 394
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
        Legend.Visible = False
        Title.Font.Color = clBlack
        Title.Font.Height = -16
        Title.Font.Name = 'GOST type B'
        Title.Text.Strings = (
          
            #1043#1088#1072#1092#1080#1082' '#1092#1091#1085#1082#1094#1080#1080' '#1088#1077#1079#1091#1083#1100#1090#1080#1088#1091#1102#1097#1077#1081' '#1087#1086#1075#1088#1077#1096#1085#1086#1089#1090#1080' '#1080#1085#1090#1077#1088#1087#1086#1083#1103#1094#1080#1086#1085#1085#1086#1075#1086' '#1087#1086#1083#1080 +
            #1085#1086#1084#1072' E(x) = abs(F(x) - P(x))')
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
      object ErrorSaveButton: TButton
        Left = 3
        Top = 400
        Width = 786
        Height = 36
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = ErrorSaveButtonClick
      end
    end
    object ValueTabSheet: TTabSheet
      Caption = #1058#1072#1073#1083#1080#1094#1072' '#1079#1085#1072#1095#1077#1085#1080#1081
      ImageIndex = 2
      ExplicitTop = 24
      ExplicitHeight = 443
      object ValueTableMemo: TMemo
        Left = 0
        Top = 0
        Width = 792
        Height = 384
        Align = alTop
        Lines.Strings = (
          '  x  '#9#9' F(x)'#9#9' P(x)'#9#9' E(x)')
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
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
      ExplicitTop = 24
      ExplicitHeight = 443
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
  object SaveChartDialog_FP: TSaveDialog
    DefaultExt = 'bmp'
    FileName = 'functions'
    Left = 716
    Top = 370
  end
  object SaveChartDialog_E: TSaveDialog
    DefaultExt = 'bmp'
    FileName = 'error'
    Left = 716
    Top = 322
  end
end
