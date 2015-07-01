<GameProjectFile>
  <PropertyGroup Type="Node" Name="Dog" ID="fe0007db-f8a9-4c92-9db4-c6cc2c237818" Version="2.2.8.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="151" Speed="1.0000" ActivedAnimationName="walk">
        <Timeline ActionTag="-2066128753" Property="Position">
          <PointFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="125" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="151" X="0.0000" Y="54.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-2066128753" Property="Scale">
          <ScaleFrame FrameIndex="1" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="125" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-2066128753" Property="RotationSkew">
          <ScaleFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="10.0000" Y="10.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="90" X="-10.0000" Y="-10.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="120" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="125" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="walk" StartIndex="1" EndIndex="121">
          <RenderColor A="255" R="0" G="100" B="0" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Animal" Tag="16" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="image" ActionTag="-2066128753" Tag="8" Rotation="-2.0000" RotationSkewX="-2.0000" RotationSkewY="-2.0000" IconVisible="False" LeftMargin="-200.0000" RightMargin="-200.0000" TopMargin="-400.0000" ctype="SpriteObjectData">
            <Size X="400.0000" Y="400.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="dog.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>