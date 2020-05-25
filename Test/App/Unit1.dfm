object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 336
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ScalableLed1: TScalableLed
    Left = 72
    Top = 32
    Width = 49
    Height = 49
    RingSizePercent = 5.000000000000000000
    TrueColor = clLime
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 96
    Top = 112
  end
end
