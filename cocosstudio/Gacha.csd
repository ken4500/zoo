<GameProjectFile>
  <PropertyGroup Type="Node" Name="Gacha" ID="4163edd1-7cfa-4ccb-a308-f827112b5dd0" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="231" Speed="1.0000" ActivedAnimationName="gacha1">
        <Timeline ActionTag="-1437413616" Property="Position">
          <PointFrame FrameIndex="1" X="0.0000" Y="-25.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="22" X="0.0000" Y="40.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="42" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="130" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1437413616" Property="Scale">
          <ScaleFrame FrameIndex="1" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="22" X="0.9000" Y="1.1000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="42" X="1.0000" Y="1.0000">
            <EasingData Type="2" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="130" X="1.4000" Y="0.7000">
            <EasingData Type="3" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="140" X="0.5000" Y="1.6000">
            <EasingData Type="3" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="150" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="201" X="1.0000" Y="1.0000">
            <EasingData Type="2" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="210" X="1.2000" Y="0.8000">
            <EasingData Type="1" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="220" X="0.8000" Y="1.2000">
            <EasingData Type="6" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="231" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1437413616" Property="RotationSkew">
          <ScaleFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="3" X="10.0000" Y="10.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="9" X="-10.0000" Y="-10.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="15" X="10.0000" Y="10.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="21" X="-10.0000" Y="-10.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="27" X="10.0000" Y="10.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="33" X="-10.0000" Y="-10.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="39" X="10.0000" Y="10.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="42" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="520973104" Property="Position">
          <PointFrame FrameIndex="1" X="0.0000" Y="-40.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="gacha1" StartIndex="1" EndIndex="150">
          <RenderColor A="255" R="127" G="255" B="0" />
        </AnimationInfo>
        <AnimationInfo Name="gacha2" StartIndex="201" EndIndex="231">
          <RenderColor A="255" R="75" G="0" B="130" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Gacha" Tag="9" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="chara_shadow_2" ActionTag="-738948805" Tag="202" Alpha="111" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="-50.0000" RightMargin="-50.0000" TopMargin="-80.0000" BottomMargin="-20.0000" ctype="SpriteObjectData">
            <Size X="100.0000" Y="100.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="30.0000" />
            <Scale ScaleX="4.0000" ScaleY="1.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.2500" Y="0.2500" />
            <FileData Type="Normal" Path="ui/chara_shadow.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="image" ActionTag="-1437413616" Tag="10" IconVisible="False" LeftMargin="-200.0000" RightMargin="-200.0000" TopMargin="-375.0000" BottomMargin="-25.0000" ctype="SpriteObjectData">
            <Size X="400.0000" Y="400.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position Y="-25.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="ui/tubo_ao.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="price" ActionTag="520973104" Tag="102" IconVisible="True" TopMargin="40.0000" BottomMargin="-40.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <AnchorPoint />
            <Position Y="-40.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Price.csd" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>