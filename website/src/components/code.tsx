import Link from "@docusaurus/Link";
import useDocusaurusContext from "@docusaurus/useDocusaurusContext";
import CodeBlock from "@theme/CodeBlock";
import { useMemo } from "react";

interface CodeProps {
  children: string;
  sourcePath?: string;
  language?: string;
  startMarker?: string;
  endMarker?: string;
  commentStyle?: string;
}

export default function Code({ children: source, language = "cpp", commentStyle = "//", startMarker, endMarker, sourcePath }: CodeProps) {
  const { siteConfig } = useDocusaurusContext();

  const { snippet, startLine, endLine } = useMemo(() => {
    const lines = source.split("\n").map((l, i) => [i, l] satisfies [number, string]);
    if (!(startMarker || endMarker)) return { snippet: source, startLine: 1, endLine: lines.length + 1 };

    const startLine = lines.filter(([i, l]) => l.match(new RegExp(`^\\s*${commentStyle}\\s*${startMarker}\\s*$`)));
    const startLineNum = startLine.length ? startLine[0][0] : -1;

    const endLine = lines.filter(([i, l]) => l.match(new RegExp(`^\\s*${commentStyle}\\s*${endMarker}\\s*$`)));
    const endLineNum = endLine.length ? endLine[0][0] : lines.length + 1;

    const snippet = lines
      .filter(([i, _]) => i > startLineNum && i < endLineNum)
      .map(([_, l]) => l)
      .join("\n");

    return { snippet, startLine: startLineNum + 2, endLine: endLineNum + 1 };
  }, [startMarker, endMarker, commentStyle, source]);

  const url =
    "https://" +
    [
      siteConfig.githubHost,
      siteConfig.organizationName,
      siteConfig.projectName,
      "blob",
      siteConfig.deploymentBranch,
      "tab",
      sourcePath,
      `#L${startLine}-L${endLine}`,
    ].join("/");

  const title = sourcePath ? <Link href={url}>{sourcePath}</Link> : undefined;

  return (
    <CodeBlock language={language} showLineNumbers={startLine} title={title}>
      {snippet}
    </CodeBlock>
  );
}
