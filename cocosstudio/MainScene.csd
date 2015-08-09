<GameProjectFile>
  <PropertyGroup Type="Scene" Name="MainScene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="259" Speed="1.0000" ActivedAnimationName="battle_start">
        <Timeline ActionTag="1751926304" Property="Position">
          <PointFrame FrameIndex="125" X="568.0000" Y="320.0000">
            <EasingData Type="1" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="1751926304" Property="Scale">
          <ScaleFrame FrameIndex="1" X="5.0000" Y="5.0000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="15" X="1.0000" Y="1.0000">
            <EasingData Type="25" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="0.9000" Y="0.9000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="25" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="125" X="1.0000" Y="1.0000">
            <EasingData Type="1" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="134" X="5.0000" Y="5.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1751926304" Property="RotationSkew">
          <ScaleFrame FrameIndex="20" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="125" X="0.0000" Y="0.0000">
            <EasingData Type="1" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1751926304" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="15" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="125" Value="255">
            <EasingData Type="1" />
          </IntFrame>
          <IntFrame FrameIndex="134" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="1751926304" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="1" Tween="False" Value="True" />
          <BoolFrame FrameIndex="125" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="902696947" Property="Position">
          <PointFrame FrameIndex="240" X="568.0000" Y="320.0000">
            <EasingData Type="1" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="902696947" Property="Scale">
          <ScaleFrame FrameIndex="141" X="5.0000" Y="5.0000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="155" X="1.0000" Y="1.0000">
            <EasingData Type="25" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="160" X="0.9000" Y="0.9000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="165" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="240" X="1.0000" Y="1.0000">
            <EasingData Type="1" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="259" X="5.0000" Y="5.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="902696947" Property="RotationSkew">
          <ScaleFrame FrameIndex="240" X="0.0000" Y="0.0000">
            <EasingData Type="1" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="902696947" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="141" Tween="False" Value="True" />
          <BoolFrame FrameIndex="240" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="902696947" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="155" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="240" Value="255">
            <EasingData Type="1" />
          </IntFrame>
          <IntFrame FrameIndex="259" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="902696947" Property="FileData">
          <TextureFrame FrameIndex="202" Tween="False">
            <TextureFile Type="Normal" Path="ui/battle_start.png" Plist="" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="zoomout1" StartIndex="1" EndIndex="135">
          <RenderColor A="255" R="189" G="183" B="107" />
        </AnimationInfo>
        <AnimationInfo Name="default" StartIndex="0" EndIndex="0">
          <RenderColor A="255" R="100" G="149" B="237" />
        </AnimationInfo>
        <AnimationInfo Name="battle_start" StartIndex="140" EndIndex="260">
          <RenderColor A="255" R="255" G="250" B="205" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="1136.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="hpGauge" ActionTag="2133434766" Tag="427" VisibleForFrame="False" IconVisible="True" LeftMargin="1109.5601" RightMargin="26.4399" TopMargin="520.0000" BottomMargin="120.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="1109.5601" Y="120.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9767" Y="0.1875" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="HpGauge.csd" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="levelup" ActionTag="1751926304" Tag="16" Alpha="0" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="144.5000" RightMargin="144.5000" TopMargin="239.0000" BottomMargin="239.0000" ctype="SpriteObjectData">
            <Size X="847.0000" Y="162.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="320.0000" />
            <Scale ScaleX="5.0000" ScaleY="5.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.7210" Y="0.2078" />
            <FileData Type="Normal" Path="ui/levelup.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="battleStart" ActionTag="902696947" Tag="17" VisibleForFrame="False" Alpha="230" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="76.5000" RightMargin="76.5000" TopMargin="247.5000" BottomMargin="247.5000" ctype="SpriteObjectData">
            <Size X="983.0000" Y="145.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="320.0000" />
            <Scale ScaleX="5.0000" ScaleY="5.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.6197" Y="0.1234" />
            <FileData Type="Normal" Path="ui/battle_start.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="scaleBar" ActionTag="-840124772" Tag="19" IconVisible="True" LeftMargin="1106.0000" RightMargin="30.0000" TopMargin="620.0000" BottomMargin="20.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="1106.0000" Y="20.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9736" Y="0.0313" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="ScaleBar.csd" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="menuNode" ActionTag="-2046749336" Tag="12" IconVisible="True" LeftMargin="30.0000" RightMargin="1106.0000" TopMargin="610.0000" BottomMargin="30.0000" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="battleButton" ActionTag="280631743" Tag="71" IconVisible="False" LeftMargin="-0.5840" RightMargin="-201.4160" TopMargin="-199.6160" BottomMargin="-0.3840" TouchEnable="True" FontSize="48" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="172" Scale9Height="178" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="202.0000" Y="200.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.4160" Y="99.6160" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="ui/battle_button.png" Plist="" />
                <NormalFileData Type="Normal" Path="ui/battle_button.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="hart" ActionTag="-1146902275" Tag="29" IconVisible="False" LeftMargin="-0.0002" RightMargin="-106.9998" TopMargin="-327.9997" BottomMargin="235.9997" ctype="SpriteObjectData">
                <Size X="107.0000" Y="92.0000" />
                <AnchorPoint />
                <Position X="-0.0002" Y="235.9997" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="ui/hart.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="coin" ActionTag="1389668671" Tag="28" IconVisible="False" LeftMargin="-0.0002" RightMargin="-101.9998" TopMargin="-415.9995" BottomMargin="315.9995" ctype="SpriteObjectData">
                <Size X="102.0000" Y="100.0000" />
                <AnchorPoint />
                <Position X="-0.0002" Y="315.9995" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="ui/coin.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="coinText" ActionTag="-1009041307" Tag="33" IconVisible="False" LeftMargin="84.9987" RightMargin="-153.9987" TopMargin="-396.9995" BottomMargin="315.9995" LabelText="x5" ctype="TextBMFontObjectData">
                <Size X="69.0000" Y="81.0000" />
                <AnchorPoint />
                <Position X="84.9987" Y="315.9995" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="hartText" ActionTag="12703591" Tag="34" IconVisible="False" LeftMargin="84.9987" RightMargin="-184.9987" TopMargin="-316.9997" BottomMargin="235.9997" LabelText="5/5" ctype="TextBMFontObjectData">
                <Size X="100.0000" Y="81.0000" />
                <AnchorPoint />
                <Position X="84.9987" Y="235.9997" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="repairTimeText" ActionTag="-585567466" Tag="36" IconVisible="False" LeftMargin="93.7191" RightMargin="-234.7191" TopMargin="-280.7700" BottomMargin="199.7700" LabelText="0:00" ctype="TextBMFontObjectData">
                <Size X="141.0000" Y="81.0000" />
                <AnchorPoint />
                <Position X="93.7191" Y="199.7700" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="otherMenu" ActionTag="-48313706" Tag="58" IconVisible="False" LeftMargin="211.9588" RightMargin="-311.9588" TopMargin="-100.3300" BottomMargin="6.3300" TouchEnable="True" FontSize="24" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="72" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="100.0000" Y="94.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="261.9588" Y="53.3300" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="ui/menu.png" Plist="" />
                <NormalFileData Type="Normal" Path="ui/menu.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="diamond" ActionTag="-2044259099" Tag="587" IconVisible="False" LeftMargin="-43.0002" RightMargin="-128.9998" TopMargin="-511.2217" BottomMargin="363.2217" ctype="SpriteObjectData">
                <Size X="172.0000" Y="148.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="42.9998" Y="437.2217" />
                <Scale ScaleX="0.5000" ScaleY="0.5000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="ui/diamond.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="diamondText" ActionTag="-2134201600" Tag="588" IconVisible="False" LeftMargin="82.8853" RightMargin="-151.8853" TopMargin="-491.4778" BottomMargin="410.4778" LabelText="x5" ctype="TextBMFontObjectData">
                <Size X="69.0000" Y="81.0000" />
                <AnchorPoint />
                <Position X="82.8853" Y="410.4778" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="30.0000" Y="30.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.0264" Y="0.0469" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="time_back" ActionTag="1631365237" Tag="172" VisibleForFrame="False" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="492.5000" RightMargin="492.5000" TopMargin="12.8000" BottomMargin="484.2000" ctype="SpriteObjectData">
            <Size X="151.0000" Y="143.0000" />
            <Children>
              <AbstractNodeData Name="timeLabel" ActionTag="583941696" Tag="29" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="37.0000" RightMargin="37.0000" TopMargin="31.0000" BottomMargin="31.0000" LabelText="30" ctype="TextBMFontObjectData">
                <Size X="77.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="75.5000" Y="71.5000" />
                <Scale ScaleX="1.6000" ScaleY="1.6000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.5099" Y="0.5664" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="568.0000" Y="627.2000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.9800" />
            <PreSize X="0.1329" Y="0.2234" />
            <FileData Type="Normal" Path="ui/time_back.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="endButton" ActionTag="811670514" Tag="47" Alpha="0" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="951.0000" RightMargin="30.0000" TopMargin="25.6000" BottomMargin="459.4000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="127" Scale9Height="133" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="155.0000" Y="155.0000" />
            <AnchorPoint ScaleX="1.0000" ScaleY="1.0000" />
            <Position X="1106.0000" Y="614.4000" />
            <Scale ScaleX="0.7000" ScaleY="0.7000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9736" Y="0.9600" />
            <PreSize X="0.1364" Y="0.2422" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="ui/close.png" Plist="" />
            <NormalFileData Type="Normal" Path="ui/close.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="weightLabel" ActionTag="1666255966" Tag="361" IconVisible="False" LeftMargin="921.5630" RightMargin="-58.5630" TopMargin="427.6422" BottomMargin="127.3578" LabelText="123.45kg" ctype="TextBMFontObjectData">
            <Size X="273.0000" Y="85.0000" />
            <AnchorPoint />
            <Position X="921.5630" Y="127.3578" />
            <Scale ScaleX="0.6500" ScaleY="0.6500" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.8112" Y="0.1990" />
            <PreSize X="0.2403" Y="0.1328" />
            <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font3.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="levelBack" ActionTag="-1789988531" Tag="241" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="415.0000" RightMargin="415.0000" TopMargin="-34.8000" BottomMargin="558.8000" ctype="SpriteObjectData">
            <Size X="306.0000" Y="116.0000" />
            <Children>
              <AbstractNodeData Name="levelLabel" ActionTag="1209458093" Tag="19" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="13.5000" RightMargin="13.5000" TopMargin="25.0000" BottomMargin="10.0000" LabelText="LEVEL 3" ctype="TextBMFontObjectData">
                <Size X="279.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" />
                <Position X="153.0000" Y="10.0000" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.0862" />
                <PreSize X="0.9118" Y="0.6983" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.7000" />
            <Position X="568.0000" Y="640.0000" />
            <Scale ScaleX="0.8000" ScaleY="0.8000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="1.0000" />
            <PreSize X="0.2694" Y="0.1813" />
            <FileData Type="Normal" Path="ui/level_back.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="weightImage" ActionTag="-1625476925" Tag="283" IconVisible="False" LeftMargin="854.3035" RightMargin="217.6965" TopMargin="451.3923" BottomMargin="125.6077" ctype="SpriteObjectData">
            <Size X="64.0000" Y="63.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="886.3035" Y="157.1077" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7802" Y="0.2455" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="ui/weight_image.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>