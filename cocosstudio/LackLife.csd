<GameProjectFile>
  <PropertyGroup Type="Layer" Name="LackLife" ID="877dbb23-7626-421e-b78f-1b2e8a952ff9" Version="2.3.2.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Layer" CustomClassName="LackLife" Tag="178" ctype="GameLayerObjectData">
        <Size X="1136.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="menu" ActionTag="-720490404" Tag="179" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="287.0000" RightMargin="287.0000" TopMargin="71.7000" BottomMargin="-30.7000" ctype="SpriteObjectData">
            <Size X="562.0000" Y="599.0000" />
            <Children>
              <AbstractNodeData Name="title" ActionTag="-235556757" Tag="180" IconVisible="False" LeftMargin="110.8893" RightMargin="124.1107" TopMargin="46.2651" BottomMargin="471.7349" LabelText="確認" ctype="TextBMFontObjectData">
                <Size X="140.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="274.3893" Y="512.2349" />
                <Scale ScaleX="0.6000" ScaleY="0.7000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4882" Y="0.8552" />
                <PreSize X="0.0000" Y="0.0000" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="noticeMessage1" ActionTag="1252780630" Tag="181" IconVisible="False" PositionPercentXEnabled="True" HorizontalEdge="BothEdge" LeftMargin="133.0000" RightMargin="133.0000" TopMargin="182.5300" BottomMargin="384.4700" FontSize="32" LabelText="ライフが足りません" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="296.0000" Y="32.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
                <Position X="281.0000" Y="416.4700" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="60" G="30" B="10" />
                <PrePosition X="0.5000" Y="0.6953" />
                <PreSize X="0.4306" Y="0.0434" />
                <FontResource Type="Normal" Path="font/yasashisa.ttf" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="noticeMessage2" ActionTag="1570341492" Tag="186" IconVisible="False" LeftMargin="75.9286" RightMargin="62.0714" TopMargin="263.5291" BottomMargin="283.4709" FontSize="26" LabelText="動画広告を視聴して回復しますか？&#xA;ライフは時間でも回復します。" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
                <Size X="424.0000" Y="52.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
                <Position X="287.9286" Y="335.4709" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="60" G="30" B="10" />
                <PrePosition X="0.5123" Y="0.5601" />
                <PreSize X="0.0000" Y="0.0000" />
                <FontResource Type="Normal" Path="font/yasashisa.ttf" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="yesButton" ActionTag="-1172564788" Tag="182" IconVisible="False" PositionPercentXEnabled="True" HorizontalEdge="BothEdge" LeftMargin="69.7600" RightMargin="292.2400" TopMargin="363.5430" BottomMargin="115.4570" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="275" Scale9Height="112" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="200.0000" Y="120.0000" />
                <Children>
                  <AbstractNodeData Name="label" ActionTag="-515433703" Tag="183" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="35.5000" RightMargin="35.5000" TopMargin="19.5000" BottomMargin="19.5000" LabelText="YES" ctype="TextBMFontObjectData">
                    <Size X="129.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="100.0000" Y="60.0000" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.5000" Y="0.5000" />
                    <PreSize X="0.8342" Y="0.7700" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
                <Position X="269.7600" Y="175.4570" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.4800" Y="0.2929" />
                <PreSize X="0.3559" Y="0.2003" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="ui/button02.png" Plist="" />
                <NormalFileData Type="Normal" Path="ui/button02.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="noButton" ActionTag="167215130" Tag="184" IconVisible="False" PositionPercentXEnabled="True" HorizontalEdge="BothEdge" LeftMargin="292.2400" RightMargin="69.7600" TopMargin="363.5430" BottomMargin="115.4570" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="30" RightEage="30" TopEage="30" BottomEage="30" Scale9OriginX="30" Scale9OriginY="30" Scale9Width="245" Scale9Height="74" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="200.0000" Y="120.0000" />
                <Children>
                  <AbstractNodeData Name="label" ActionTag="-1118217533" Tag="185" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="36.5000" RightMargin="51.5000" TopMargin="16.0320" BottomMargin="22.9680" LabelText="NO" ctype="TextBMFontObjectData">
                    <Size X="112.0000" Y="81.0000" />
                    <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                    <Position X="92.5000" Y="63.4680" />
                    <Scale ScaleX="1.0000" ScaleY="1.0000" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <PrePosition X="0.4625" Y="0.5289" />
                    <PreSize X="0.8342" Y="0.7700" />
                    <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
                  </AbstractNodeData>
                </Children>
                <AnchorPoint ScaleY="0.5000" />
                <Position X="292.2400" Y="175.4570" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5200" Y="0.2929" />
                <PreSize X="0.3559" Y="0.2003" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="ui/button02.png" Plist="" />
                <NormalFileData Type="Normal" Path="ui/button02.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="268.8000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.4200" />
            <PreSize X="0.4947" Y="0.9359" />
            <FileData Type="Normal" Path="ui/menu3.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>