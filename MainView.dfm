object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = #1048#1085#1090#1077#1088#1087#1086#1083#1080#1088#1086#1074#1072#1085#1080#1077' '#1092#1091#1085#1082#1094#1080#1081
  ClientHeight = 705
  ClientWidth = 825
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Times New Roman'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 19
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 369
    Height = 17
    AutoSize = False
    Caption = #1042#1080#1076' '#1080#1085#1090#1077#1088#1087#1086#1083#1103#1094#1080#1086#1085#1085#1086#1075#1086' '#1087#1086#1083#1080#1085#1086#1084#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 31
    Width = 369
    Height = 18
    AutoSize = False
    Caption = 'P(x) = a'#8320' + a'#8321'x + a'#8322'x'#178' + ... + a'#8345'x'#8319
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 16
    Top = 71
    Width = 369
    Height = 26
    AutoSize = False
    Caption = #1042#1080#1076' '#1080#1085#1090#1077#1088#1087#1086#1083#1080#1088#1091#1077#1084#1086#1081' '#1092#1091#1085#1082#1094#1080#1080':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 16
    Top = 103
    Width = 41
    Height = 26
    AutoSize = False
    Caption = 'f(x) = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 16
    Top = 135
    Width = 369
    Height = 26
    AutoSize = False
    Caption = #1048#1085#1090#1077#1088#1074#1072#1083' '#1080#1085#1090#1077#1088#1087#1086#1083#1103#1094#1080#1080':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 55
    Top = 167
    Width = 60
    Height = 20
    AutoSize = False
    Caption = 'a '#8804' |10|'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 161
    Top = 167
    Width = 40
    Height = 20
    AutoSize = False
    Caption = 'a ='
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label8: TLabel
    Left = 55
    Top = 201
    Width = 60
    Height = 20
    AutoSize = False
    Caption = 'b '#8804' |10|'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label9: TLabel
    Left = 161
    Top = 201
    Width = 40
    Height = 20
    AutoSize = False
    Caption = 'b ='
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label10: TLabel
    Left = 16
    Top = 227
    Width = 369
    Height = 26
    AutoSize = False
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1091#1079#1083#1086#1074' '#1080#1085#1090#1077#1088#1087#1086#1083#1080#1088#1086#1074#1072#1085#1080#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label11: TLabel
    Left = 55
    Top = 259
    Width = 82
    Height = 20
    AutoSize = False
    Caption = '1 < N '#8804' 10'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label12: TLabel
    Left = 161
    Top = 259
    Width = 40
    Height = 20
    AutoSize = False
    Caption = 'N = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object FunctionsComboBox: TComboBox
    Left = 63
    Top = 105
    Width = 114
    Height = 27
    ItemIndex = 0
    TabOrder = 0
    Text = 'x*exp(x)'
    Items.Strings = (
      'x*exp(x)')
  end
  object AValueEdit: TEdit
    Left = 207
    Top = 167
    Width = 40
    Height = 27
    TabOrder = 1
    Text = '1,5'
  end
  object BValueEdit: TEdit
    Left = 207
    Top = 201
    Width = 40
    Height = 27
    TabOrder = 2
    Text = '4,5'
  end
  object NValueEdit: TEdit
    Left = 207
    Top = 259
    Width = 40
    Height = 27
    TabOrder = 3
    Text = '3'
  end
  object InterpolateButton: TButton
    Left = 16
    Top = 296
    Width = 369
    Height = 25
    Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1080#1085#1090#1077#1088#1087#1086#1083#1080#1088#1086#1074#1072#1085#1080#1077
    TabOrder = 4
    OnClick = InterpolateButtonClick
  end
  object Chart1: TChart
    Left = 24
    Top = 344
    Width = 769
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
    TabOrder = 5
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
      Data = {
        0603000000000000000000000000000020FF0000000000000000000014400000
        0020FF0500000048656C6C6F0000000000000000FFFFFF1FFF00000000}
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
      Data = {
        011900000000000000000000002085EB51B81EFD3F555555555555B53F5D8FC2
        F5285CF73F555555555555C53F676666666666F63F000000000000D03F15AE47
        E17A14F23F555555555555D53FAF47E17A14AEEF3FAAAAAAAAAAAADA3F15AE47
        E17A14EE3FFFFFFFFFFFFFDF3FEC51B81E85EBE13FAAAAAAAAAAAAE23FCECCCC
        CCCCCCDC3F555555555555E53F7B14AE47E17AE43F000000000000E83FE27A14
        AE47E1DA3FABAAAAAAAAAAEA3FE951B81E85EBB13F565555555555ED3FC3F528
        5C8FC2D53F000000000000F03F9D9999999999A93F555555555555F13F85EB51
        B81E85DB3FAAAAAAAAAAAAF23F14AE47E17A14DE3FFFFFFFFFFFFFF33FA3703D
        0AD7A3C03F545555555555F53F47E17A14AE47D13FA9AAAAAAAAAAF63F14AE47
        E17A14E63FFEFFFFFFFFFFF73F323333333333D33F535555555555F93F959999
        999999B93FA8AAAAAAAAAAFA3FA2703D0AD7A3C03FFDFFFFFFFFFFFB3FC1F528
        5C8FC2C53F525555555555FD3FBA1E85EB51B8CE3FA7AAAAAAAAAAFE3F49E17A
        14AE47D13FFCFFFFFFFFFFFF3F313333333333C33F}
      Detail = {0000000000}
    end
  end
end
