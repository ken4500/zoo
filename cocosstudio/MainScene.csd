<GameProjectFile>
  <PropertyGroup Type="Scene" Name="MainScene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="2.2.8.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="134" Speed="1.0000" ActivedAnimationName="zoomout1">
        <Timeline ActionTag="538608515" Property="Position">
          <PointFrame FrameIndex="0" X="568.0000" Y="320.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="1" X="568.0000" Y="320.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="15" X="568.0000" Y="320.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="125" X="568.0000" Y="320.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="134" X="568.0000" Y="320.0000">
            <EasingData Type="27" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="538608515" Property="Scale">
          <ScaleFrame FrameIndex="0" X="5.0000" Y="5.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="1" X="5.0000" Y="5.0000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="15" X="1.0000" Y="1.0000">
            <EasingData Type="27" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="0.9000" Y="0.9000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="25" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="95" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="125" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="134" X="5.0000" Y="5.0000">
            <EasingData Type="27" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="538608515" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="125" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="134" X="0.0000" Y="0.0000">
            <EasingData Type="27" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="538608515" Property="VisibleForFrame">
          <BoolFrame FrameIndex="0" Tween="False" Value="False" />
          <BoolFrame FrameIndex="1" Tween="False" Value="True" />
          <BoolFrame FrameIndex="15" Tween="False" Value="True" />
          <BoolFrame FrameIndex="125" Tween="False" Value="True" />
          <BoolFrame FrameIndex="134" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="538608515" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="1" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="15" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="95" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="125" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="134" Value="0">
            <EasingData Type="27" />
          </IntFrame>
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
      </AnimationList>
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="1136.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="lavelupLabel" ActionTag="538608515" Tag="44" VisibleForFrame="False" Alpha="0" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="302.5000" RightMargin="302.5000" TopMargin="248.5000" BottomMargin="248.5000" LabelText="LEVELUP!" ctype="TextBMFontObjectData">
            <Size X="531.0000" Y="143.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="568.0000" Y="320.0000" />
            <Scale ScaleX="5.0000" ScaleY="5.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.4250" Y="0.0750" />
            <LabelBMFontFile_CNB Type="Normal" Path="font1.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="scaleBar" ActionTag="-840124772" Tag="19" IconVisible="True" PositionPercentXEnabled="True" LeftMargin="1090.5599" RightMargin="45.4401" TopMargin="620.0000" BottomMargin="20.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
            <Size />
            <AnchorPoint />
            <Position X="1090.5599" Y="20.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9600" Y="0.0313" />
            <PreSize />
            <FileData Type="Normal" Path="ScaleBar.csd" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="Button_1" ActionTag="280631743" Tag="71" Alpha="225" IconVisible="False" LeftMargin="31.7862" RightMargin="904.2138" TopMargin="461.8942" BottomMargin="28.1058" TouchEnable="True" FontSize="48" ButtonText="Battle" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" OutlineSize="1" ShadowOffsetX="2" ShadowOffsetY="-2" ctype="ButtonObjectData">
            <Size X="200.0000" Y="150.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="131.7862" Y="103.1058" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1160" Y="0.1611" />
            <PreSize X="0.1761" Y="0.2344" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>