<GameProjectFile>
  <PropertyGroup Type="Node" Name="Gacha" ID="4163edd1-7cfa-4ccb-a308-f827112b5dd0" Version="2.2.8.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="60" Speed="1.0000" ActivedAnimationName="test">
        <Timeline ActionTag="-1437413616" Property="Position">
          <PointFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="60" X="0.0000" Y="52.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1437413616" Property="Scale">
          <ScaleFrame FrameIndex="1" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1437413616" Property="RotationSkew">
          <ScaleFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="test" StartIndex="1" EndIndex="60">
          <RenderColor A="150" R="127" G="255" B="0" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Gacha" Tag="9" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="image" ActionTag="-1437413616" Tag="10" IconVisible="False" LeftMargin="-182.0000" RightMargin="-182.0000" TopMargin="-436.0000" ctype="SpriteObjectData">
            <Size X="364.0000" Y="436.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="house.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>