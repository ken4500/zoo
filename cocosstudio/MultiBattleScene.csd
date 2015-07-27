<GameProjectFile>
  <PropertyGroup Type="Scene" Name="MultiBattleScene" ID="4bfcc15e-6245-4d1b-af3c-35fa46aa6354" Version="2.3.1.1" />
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
        <Timeline ActionTag="-840124772" Property="Position">
          <PointFrame FrameIndex="1" X="1090.5599" Y="20.0000">
            <EasingData Type="0" />
          </PointFrame>
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
          <AbstractNodeData Name="levelup" ActionTag="1751926304" Tag="16" Alpha="0" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="158.5000" RightMargin="158.5000" TopMargin="253.5000" BottomMargin="253.5000" ctype="SpriteObjectData">
            <Size X="819.0000" Y="133.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="320.0000" />
            <Scale ScaleX="5.0000" ScaleY="5.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.7210" Y="0.2078" />
            <FileData Type="Normal" Path="ui/levelup.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="battleStart" ActionTag="902696947" Tag="17" VisibleForFrame="False" Alpha="230" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="100.0000" RightMargin="100.0000" TopMargin="258.0000" BottomMargin="258.0000" ctype="SpriteObjectData">
            <Size X="936.0000" Y="124.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="320.0000" />
            <Scale ScaleX="5.0000" ScaleY="5.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.6197" Y="0.1234" />
            <FileData Type="Normal" Path="ui/battle_start.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="scaleBar" ActionTag="-840124772" Tag="19" IconVisible="True" PositionPercentXEnabled="True" LeftMargin="1090.5599" RightMargin="45.4401" TopMargin="620.0000" BottomMargin="20.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position X="1090.5599" Y="20.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9600" Y="0.0313" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="ScaleBar.csd" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="menuNode" ActionTag="-2046749336" Tag="12" IconVisible="True" LeftMargin="33.0452" RightMargin="1102.9548" TopMargin="608.6856" BottomMargin="31.3144" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="coin" ActionTag="1389668671" Tag="28" IconVisible="False" RightMargin="-192.0000" TopMargin="-187.0000" ctype="SpriteObjectData">
                <Size X="192.0000" Y="187.0000" />
                <AnchorPoint />
                <Position />
                <Scale ScaleX="0.4000" ScaleY="0.4000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="ui/coin.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="coinText" ActionTag="-1009041307" Tag="33" IconVisible="False" LeftMargin="100.0000" RightMargin="-165.0000" TopMargin="-77.0000" LabelText="x5" ctype="TextBMFontObjectData">
                <Size X="65.0000" Y="77.0000" />
                <AnchorPoint />
                <Position X="100.0000" />
                <Scale ScaleX="0.8000" ScaleY="0.8000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="33.0452" Y="31.3144" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.0291" Y="0.0489" />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="timeLabel" ActionTag="583941696" Tag="29" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="531.5000" RightMargin="531.5000" TopMargin="32.0000" BottomMargin="531.0000" LabelText="30" ctype="TextBMFontObjectData">
            <Size X="73.0000" Y="77.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="568.0000" Y="608.0000" />
            <Scale ScaleX="2.0000" ScaleY="1.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.9500" />
            <PreSize X="0.0643" Y="0.1203" />
            <LabelBMFontFile_CNB Type="Normal" Path="font/zoo_font2.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="endButton" ActionTag="811670514" Tag="47" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="10.0000" RightMargin="999.0000" TopMargin="12.8000" BottomMargin="555.2000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="97" Scale9Height="50" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="127.0000" Y="72.0000" />
            <AnchorPoint ScaleY="1.0000" />
            <Position X="10.0000" Y="627.2000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.0088" Y="0.9800" />
            <PreSize X="0.1118" Y="0.1125" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="ui/end.png" Plist="" />
            <NormalFileData Type="Normal" Path="ui/end.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>