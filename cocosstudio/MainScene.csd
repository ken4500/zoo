<GameProjectFile>
  <PropertyGroup Type="Scene" Name="MainScene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="2.2.8.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="185" Speed="1.0000">
        <Timeline ActionTag="538608515" Property="Position">
          <PointFrame FrameIndex="175" X="320.0000" Y="480.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="185" X="320.0000" Y="480.0000">
            <EasingData Type="27" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="538608515" Property="Scale">
          <ScaleFrame FrameIndex="115" X="5.0000" Y="5.0000">
            <EasingData Type="27" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="145" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="175" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="185" X="5.0000" Y="5.0000">
            <EasingData Type="27" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="538608515" Property="RotationSkew">
          <ScaleFrame FrameIndex="175" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="185" X="0.0000" Y="0.0000">
            <EasingData Type="27" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="538608515" Property="VisibleForFrame">
          <BoolFrame FrameIndex="1" Tween="False" Value="False" />
          <BoolFrame FrameIndex="115" Tween="False" Value="True" />
          <BoolFrame FrameIndex="175" Tween="False" Value="True" />
          <BoolFrame FrameIndex="185" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="538608515" Property="Alpha">
          <IntFrame FrameIndex="115" Value="0">
            <EasingData Type="27" />
          </IntFrame>
          <IntFrame FrameIndex="145" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="175" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="185" Value="0">
            <EasingData Type="27" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-840124772" Property="Position">
          <PointFrame FrameIndex="1" X="1090.5599" Y="20.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1411683611" Property="Position">
          <PointFrame FrameIndex="0" X="568.0000" Y="320.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="1" X="568.0000" Y="320.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="zoomout1" StartIndex="1" EndIndex="201">
          <RenderColor A="255" R="189" G="183" B="107" />
        </AnimationInfo>
        <AnimationInfo Name="default" StartIndex="0" EndIndex="0">
          <RenderColor A="255" R="100" G="149" B="237" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="1136.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="lavelupLabel" CanEdit="False" ActionTag="538608515" Tag="44" VisibleForFrame="False" Alpha="0" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="54.5000" RightMargin="550.5000" TopMargin="88.5000" BottomMargin="408.5000" LabelText="LEVELUP!" ctype="TextBMFontObjectData">
            <Size X="531.0000" Y="143.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="320.0000" Y="480.0000" />
            <Scale ScaleX="5.0000" ScaleY="5.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2817" Y="0.7500" />
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
          <AbstractNodeData Name="gacha" ActionTag="-1411683611" Tag="47" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" RightMargin="1136.0000" TopMargin="640.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
            <Size />
            <AnchorPoint />
            <Position />
            <Scale ScaleX="0.9000" ScaleY="0.9000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="Gacha.csd" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>